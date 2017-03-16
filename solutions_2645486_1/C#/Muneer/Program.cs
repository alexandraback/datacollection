using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace ManageYourEnergyLarge
{
    class Activity
    {
        public int id;
        public int val;
        //public int minEnergyAtStart;
        public int maxEnergyAtStart;
        public int energyToLeave;
        public int energyUsed = 0;
        public bool parsed = false;
    }

    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            //StreamReader sr = new StreamReader("D:\\B-small-attempt1.in");
            //StreamWriter sw = new StreamWriter("D:\\B-small-attempt1_.out");

            StreamReader sr = new StreamReader("D:\\B-large.in");
            StreamWriter sw = new StreamWriter("D:\\B-large.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());


            for (int i = 0; i < numTestCases; i++)
            {
                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                int maximumEnergy = Convert.ToInt32(str[0]);
                int energyRegained = Convert.ToInt32(str[1]);
                int numActivities = Convert.ToInt32(str[2]);

                if (energyRegained > maximumEnergy) energyRegained = maximumEnergy;

                str = sr.ReadLine().Split(' ');

                int[] activityValues = new int[numActivities + 1];

                Activity[] activities = new Activity[numActivities];
                for (int j = 0; j < numActivities; j++)
                {
                    Activity act = new Activity();

                    act.id = j;
                    act.val = Convert.ToInt32(str[j]);
                    //act.minEnergyAtStart = energyRegained;
                    act.maxEnergyAtStart = maximumEnergy;
                    act.energyToLeave = 0;

                    activities[j] = act;
                }

                List<Activity> temp = new List<Activity>(activities);
                temp.Sort((a, b) => b.val.CompareTo(a.val));
                Activity[] activitiesSorted = temp.ToArray();


                for (int j = 0; j < numActivities; j++)
                {
                    int id = activitiesSorted[j].id;

                    activities[id].energyUsed = activities[id].maxEnergyAtStart - activities[id].energyToLeave;
                    activities[id].parsed = true;

                    int energyAvailable = activities[id].energyToLeave;

                    for (int k = id + 1; k < numActivities; k++)
                    {
                        if (activities[k].parsed) break;

                        activities[k].maxEnergyAtStart = energyAvailable + energyRegained;

                        if (activities[k].maxEnergyAtStart > maximumEnergy)
                        {
                            activities[k].maxEnergyAtStart = maximumEnergy;
                            break;
                        }
                        energyAvailable = activities[k].maxEnergyAtStart;
                    }


                    int energyRequired = activities[id].maxEnergyAtStart - energyRegained;
                    
                    for (int k = id - 1; k >=0; k--)
                    {
                        if (activities[k].parsed) break;

                        activities[k].energyToLeave = energyRequired;

                        if (activities[k].energyToLeave < 0)
                        {
                            activities[k].energyToLeave = 0;
                            break;
                        }

                        energyRequired = activities[k].energyToLeave - energyRegained;
                    }

                }

                int totalValue = 0;

                for (int j = 0; j < numActivities; j++)
                {
                    totalValue += activities[j].val * activities[j].energyUsed;
                }

                sw.Write("Case #{0}: ", i + 1);
                sw.Write(totalValue);
                sw.WriteLine();

            }
            sw.Close();
        }
    }
}
