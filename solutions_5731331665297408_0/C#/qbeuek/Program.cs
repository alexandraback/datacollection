using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace flights
{
    class Program
    {
        class City
        {
            public int ZipCode;
            public String ZipCodeString;
            public List<City> Connections = new List<City>();
        }

        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader(@"..\..\input.txt"))
            using (var outputStream = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(inputStream.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var inputs = inputStream.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                    var citiesCount = inputs[0];
                    var connectionsCount = inputs[1];
                    var cities = new List<City>();
                    for (var i = 0; i < citiesCount; i++)
                    {
                        var city = new City() { ZipCodeString = inputStream.ReadLine() };
                        city.ZipCode = int.Parse(city.ZipCodeString);
                        cities.Add(city);
                    }
                    for (var j = 0; j < connectionsCount; j++)
                    {
                        var connection = inputStream.ReadLine().Split().Select(s => int.Parse(s) - 1).ToArray();
                        var from = connection[0];
                        var to = connection[1];
                        cities[from].Connections.Add(cities[to]);
                        cities[to].Connections.Add(cities[from]);
                    }

                    var minimumStartZip = cities.Min(c => c.ZipCode);
                    var startCity = cities.Where(c => c.ZipCode == minimumStartZip).Single();

                    var visited = new HashSet<City>();
                    var nextChoices = new HashSet<City>();
                    var result = BuildVists(startCity, visited, nextChoices);

                    outputStream.WriteLine("Case #{0}: {1}", caseNumber, result);
                }
            }
        }

        private static string BuildVists(City currentCity, HashSet<City> visited, HashSet<City> nextChoices)
        {
            var result = currentCity.ZipCodeString;
            visited.Add(currentCity);
            while (true)
            {
                var unvisitedCities = currentCity.Connections.Where(c => !visited.Contains(c)).OrderBy(c => c.ZipCode).ToArray();
                if (unvisitedCities.Length == 0)
                    break;
                var nextCity = unvisitedCities[0];

                if (nextChoices.Count > 0 && nextChoices.Min(c => c.ZipCode) < nextCity.ZipCode)
                {
                    //potentially we can trace back if all unvisited nodes are still reachable by remaining nodes
                    var nodesToBeReached = new HashSet<City>();
                    var canReach = true;
                    for (var i = 0; i < unvisitedCities.Length; i++)
                    {
                        var subVisited = new HashSet<City>(visited);
                        if (!CanReach(unvisitedCities[i], nextChoices, subVisited))
                        {
                            canReach = false;
                            break;
                        }
                    }
                    if (canReach)
                        return result;

                }

                var addedChoices = new List<City>();
                for (var i = 1; i < unvisitedCities.Length; i++)
                {
                    if (!nextChoices.Contains(unvisitedCities[i]))
                    {
                        nextChoices.Add(unvisitedCities[i]);
                        addedChoices.Add(unvisitedCities[i]);
                    }
                }
                result += BuildVists(nextCity, visited, nextChoices);
                foreach (var addedChoice in addedChoices)
                {
                    nextChoices.Remove(addedChoice);
                }
            }

            return result;
        }

        private static bool CanReach(City city, HashSet<City> nextChoices, HashSet<City> subVisited)
        {
            if (nextChoices.Contains(city))
                return true;

            subVisited.Add(city);
            var canReach = false;
            foreach (var nextCity in city.Connections)
            {
                if (!subVisited.Contains(nextCity))
                    if (CanReach(nextCity, nextChoices, subVisited))
                    {
                        canReach = true;
                        break;
                    }
            }
            subVisited.Remove(city);
            return canReach;
        }
    }
}
