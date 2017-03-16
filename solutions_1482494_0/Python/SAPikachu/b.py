import sys
from pprint import pprint

def solve():
    levels = int(sys.stdin.readline().strip())
    ratings = {}
    for i in range(levels):
        rating = \
            [int(x) for x in sys.stdin.readline().strip().split(" ")]
        
        ratings[i] = {
            "level": i, 
            "rating1": rating[0],
            "rating2": rating[1],
        }

    stars = 0
    played = 0
    sorted_rating1 = list(ratings.values())
    sorted_rating1.sort(key=lambda x: x["rating1"] * 10000 + 10000 - x["rating2"])
    sorted_rating2 = list(ratings.values())
    sorted_rating2.sort(key=lambda x: x["rating2"] * 10000 + 10000 - x["rating1"])

    while len(ratings) > 0:
        if sorted_rating2[0]["rating2"] <= stars:
            if "played_level1" in sorted_rating2[0]:
                stars += 1
            else:
                stars += 2
                sorted_rating1.remove(sorted_rating2[0])

            played += 1
            assert ratings[sorted_rating2[0]["level"]]
            del ratings[sorted_rating2[0]["level"]]

            del sorted_rating2[0]
        elif len(sorted_rating1) > 0 and sorted_rating1[0]["rating1"] <= stars:
            stars += 1
            played += 1
            sorted_rating1[0]["played_level1"] = True
            assert ratings[sorted_rating1[0]["level"]]
            del sorted_rating1[0]
        else:
            return "Too Bad"

    assert len(sorted_rating1) == len(sorted_rating2) == 0
    return played


def run():
    cases = int(sys.stdin.readline().strip())
    for i in range(cases):
        print("Case #{}: {}".format(i + 1, solve()))

if __name__ == "__main__":
    run()

