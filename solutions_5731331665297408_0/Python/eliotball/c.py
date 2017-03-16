def routes(zips):
  return routes_sorted(sorted(zips))

def routes_sorted(sorted_zips):
  if len(sorted_zips) == 0:
    yield []
  for head_index in xrange(len(sorted_zips)):
    for tail in routes_sorted(sorted_zips[:head_index] + sorted_zips[head_index+1:]):
      yield [sorted_zips[head_index]] + tail

def route_possible(flights, route):
  return route_possible_sub(flights, route[1:], [route[0]])

def route_possible_sub(flights, route, returnable):
  if route == []:
    return True
  # Is the next location visitable from any of the returnable places?
  for ret_index in xrange(len(returnable) -1, -1, -1):
    if route[0] in flights[returnable[ret_index]]:
      # It is, so remove the remainder of the returnable places and continue
      return route_possible_sub(flights, route[1:], returnable[:ret_index + 1] + [route[0]])
  return False

def read_cities(count):
  return [raw_input() for c in xrange(count)]

def read_flights(count, cities):
  flight_map = {city: [] for city in cities}
  for c in xrange(count):
    points = raw_input().split(" ")
    flight_map[cities[int(points[0]) - 1]] += [cities[int(points[1]) - 1]]
    flight_map[cities[int(points[1]) - 1]] += [cities[int(points[0]) - 1]]
  return flight_map

def solve():
  counts = [int(count) for count in raw_input().split(" ")]
  cities = read_cities(counts[0])
  flights = read_flights(counts[1], cities)
  for route in routes(cities):
    if route_possible(flights, route):
      return "".join(route)

cases = int(raw_input())
for case in range(cases):
  print "Case #" + str(case + 1) + ": " + solve()
