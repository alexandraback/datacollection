/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

int tests;
int topics;
char first[32];
char second[32];
std::pair<int, int> topic[1024];

int count(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        printf("Case #%d: ", t + 1);
        int words = 0;
        std::unordered_map<std::string, int> map;
        std::unordered_map<int, int> count1, count2;
        scanf("%d", &topics);
        for(int s = 0; s < topics; ++ s)
        {
            scanf("%s %s", first, second);
            if(!map.count(std::string(first)))
                map[std::string(first)] = ++ words;

            if(!map.count(std::string(second)))
                map[std::string(second)] = ++ words;

            topic[s] = std::make_pair(map[std::string(first)], map[std::string(second)]);
            ++ count1[topic[s].first];
            ++ count2[topic[s].second];
        }

        int result = 0;
        for(int s = 0; s < topics; ++ s)
        {
            if(count1[topic[s].first] < 2 || count2[topic[s].second] < 2)
                continue;

            ++ result;
        }

        printf("%d\n", result);
    }

    return 0;
}

int count(void)
{
    int fakes = 0;
    std::unordered_map<int, bool> fst, snd;
    for(int s = 0; s < topics; ++ s)
    {
        if(fst[topic[s].first] && snd[topic[s].second])
            ++ fakes;

        fst[topic[s].first] = true;
        snd[topic[s].second] = true;
    }

    return fakes;
}
