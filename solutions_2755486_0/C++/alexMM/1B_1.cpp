// 1B_1.cpp : Defines the entry polong long for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_DISTANCE = 1000;

struct Attack
{
    int day;
    int west, east;
    int strength;
    Attack (int day, int west, int east, int strength): day (day), west (west), east (east), strength (strength)
    {

    }
    bool operator < (const Attack& other)
    {
        return day < other.day;
    }
};

int main(int argc, char* argv[])
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    long long count_of_games;
    cin >> count_of_games;
    for (long long l = 1; l <= count_of_games; ++l)
    {
        int n;
        cin >> n;
        vector <Attack> attacks;
        vector <int> heights (MAX_DISTANCE);
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            int day, num_of_attacks, west, east, strength, delta_day, distance, delta_strength;
            cin >> day >> num_of_attacks >> west >> east >> strength >> delta_day >> distance >> delta_strength;
            west = MAX_DISTANCE / 2 + 2 * west;
            east = MAX_DISTANCE / 2 + 2 * east;
            for (int j = 0; j < num_of_attacks; ++j)
            {
                Attack new_attack (day, west, east, strength);
                attacks.push_back (new_attack);
                day += delta_day;
                west += 2 * distance;
                east += 2 * distance;
                strength += delta_strength;
            }
        }
        std::sort (attacks.begin (), attacks.end ());
        for (vector <Attack>::const_iterator iter = attacks.begin (); iter != attacks.end (); ++iter)
        {
            vector <int> new_heights = heights;
            bool success = false;
            for (int i = iter->west; i <= iter->east; i++)
            {
                if (heights [i] < iter->strength)
                {
                    success = true;
                    new_heights [i] = iter->strength;
                }
            }
            if (success)
                ++answer;
            while ((iter + 1 != attacks.end ()) && ((iter + 1)->day == iter->day))
            {
                ++iter;
                success = false;
                for (int i = iter->west; i <= iter->east; i++)
                {
                    if (heights [i] < iter->strength)
                    {
                        success = true;
                        if (iter->strength > new_heights [i])
                            new_heights [i] = iter->strength;
                    }
                }
                if (success)
                    ++answer;
            }
            heights = new_heights;
        }
        cout << "Case #" << l << ": " << answer << endl;
    }
	return 0;
}

