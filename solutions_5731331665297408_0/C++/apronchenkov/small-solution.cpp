#include "matrix.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>


struct FlightMap {
    int numberOfCities;
    std::vector<std::string> zipOfCities;
    Matrix<bool> hasFlight;
};


FlightMap readFlightMap()
{
    int numberOfCities, numberOfFlights;
    std::cin >> numberOfCities >> numberOfFlights;
    FlightMap result;
    result.numberOfCities = numberOfCities;
    for (int cityNo = 0; cityNo < numberOfCities; ++cityNo) {
        std::string zip;
        std::cin >> zip;
        result.zipOfCities.push_back(zip);
    }
    result.hasFlight = Matrix<bool>(numberOfCities, numberOfCities, false);
    for (int flightNo = 0; flightNo < numberOfFlights; ++flightNo) {
        int from, to;
        std::cin >> from >> to;
        result.hasFlight.set(from - 1, to - 1, true);
        result.hasFlight.set(to - 1, from - 1, true);
    }
    return result;
}


typedef std::vector<int> Permutation;

Permutation idenitityPermutation(int size)
{
    Permutation result;
    for (int i = 0; i < size; ++i) {
        result.push_back(i);
    }
    return result;
}

bool nextPermutation(Permutation* permutation)
{
    return std::next_permutation(permutation->begin(), permutation->end());
}



std::string travelZipCode(const FlightMap& flightmap, const Permutation& travel)
{
    std::string result;
    for (int city : travel) {
        result += flightmap.zipOfCities.at(city);
    }
    return result;
}



bool isPossibleTravel(const FlightMap& flightmap, const Permutation& travel)
{
    std::stack<int> stack;
    stack.push(travel.at(0));
    for (size_t index = 1; !stack.empty() && index < travel.size(); ) {
        const int nextCity = travel[index];
        const int currentCity = stack.top();
        if (flightmap.hasFlight.get(currentCity, nextCity)) {
            ++index;
            stack.push(nextCity);
        } else {
            stack.pop();
        }
    }
    return !stack.empty();
}



int main()
{
    int numberOfCases;
    std::cin >> numberOfCases;
    for (int caseNo = 1; caseNo <= numberOfCases; ++caseNo) {
        const auto flightmap = readFlightMap();
        Permutation travel = idenitityPermutation(flightmap.numberOfCities);
        std::string minTravelZipCode = "XXX";

        do {
            const auto newTravelZipCode = travelZipCode(flightmap, travel);
            if (minTravelZipCode > newTravelZipCode && isPossibleTravel(flightmap, travel)) {
                minTravelZipCode = newTravelZipCode;
            }
        } while (nextPermutation(&travel));
        std::cout << "Case #" << caseNo << ": " << minTravelZipCode << '\n';
    }
    return 0;
    
}
