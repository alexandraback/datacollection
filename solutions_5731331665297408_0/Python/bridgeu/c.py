import sys
r = sys.stdin.readline

T = int(r())

def progress(city_list, flights, unvisited_cities, city_values):
    if not unvisited_cities:
        return ""

    usable_flights = [[fro, to] for [fro,to] in flights if (fro in city_list and to in unvisited_cities)]
    usable_flights.extend( [[to,fro] for [fro,to] in flights if (to in city_list and fro in unvisited_cities)])

    if len(usable_flights) == 0:
        return -1

    best = "9999999999999999999999"
    for [already_city, new_city] in usable_flights:
        new_city_list = [x for x in city_list]
        while new_city_list.pop() != already_city:
            pass
        new_city_list.append(already_city)
        new_city_list.append(new_city)

        new_unvisited_cities = [x for x in unvisited_cities if x != new_city]
        rest = progress(new_city_list, flights, new_unvisited_cities, city_values)
        if rest != -1:
            rest_of_list = city_values[new_city] + rest
            best = min(best, rest_of_list)

    if best == "9999999999999999999999":
        return -1

    return best

for i in range(T):
    cities, flights = map(int, r().split())

    city_values = {x:r().strip() for x in range(cities)}
    flights = [[int(x)-1 for x in r().split()] for y in range(flights)]

    start = min(city_values.items(), key=lambda x: x[1])
    ans = start[1]
    unvisited_cities = [x for x in range(cities) if x != start[0]]

    ans += progress([start[0]], flights, unvisited_cities, city_values)
    print("Case #%d: %s" % (i+1, ans))
