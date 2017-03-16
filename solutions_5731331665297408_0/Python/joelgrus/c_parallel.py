infile = "c-small-attempt1.in"
outfile = "c-small.out"

lines = [l.strip() for l in open(infile,"r")]
from collections import defaultdict, Counter
from functools import partial

num_cases = int(lines[0])
lines = lines[1:]

cases = []

for _ in range(num_cases):
    
    n, m = [int(x) for x in lines[0].split()]
    zips = lines[1:(n+1)]
    flights = lines[(n+1):(n+1+m)]
    lines = lines[(n+1+m):]
    case = n, m, zips, flights
    cases.append(case)
    
def clean_flight(flight):
    x, y = flight.split()
    return (int(x) - 1, int(y) - 1)


def score_trip(starting_city, zips, flights):
    visited = set()
    visited.add(starting_city)
    zip = zips[starting_city]
    
    current_city = starting_city
    for orig, dest in flights:
        #print current_city, ":", orig, "->", dest
        if orig != current_city:
            #print "orig is not current city!"
            return None
        # update current city
        current_city = dest
        if dest not in visited:
            #print "dest is unvisited"
            visited.add(dest)
            zip += zips[dest]
            #print "visited is now", visited
            #print "zip is now", zip
        
            
    if len(visited) < len(zips):
        #print len(zips), "zips but only", len(visited), "visited"
        return None
    if current_city != starting_city:
        #print "not back at starting city"
        return None
        
    return zip            

def flight_value(flight,city, zips):
    a, b = flight
    if a == city:
        return zips[b]
    elif b == city:
        return zips[a]
    else:
        return "a"
    
def generate_trips(n, starting_city, ending_city, flights, zips, returns=[], prev_outs=[], original_starting_city=None):
    
    if original_starting_city is None:
        original_starting_city = starting_city
    #print starting_city, flights, returns

    if starting_city == ending_city and not returns:
        yield []
        
    best_flights = sorted(flights, 
        key=lambda flight: flight_value(flight, starting_city, zips))

    for i, (a, b) in enumerate(best_flights):
        #print "checking flight", i, a, b
        if a == starting_city and b not in prev_outs and b != original_starting_city:
            #print "a is starting city"
            #print "new returns", returns + [(b,a)]
            #print "new flights", best_flights[:i] + best_flights[(i+1):]
            for rest in generate_trips(n, b,  
                                       ending_city,
                                       best_flights[:i] + best_flights[(i+1):],
                                       zips,
                                       returns + [(b,a)],
                                       prev_outs + [b],
                                       original_starting_city):
                yield [(a,b)] + rest
        elif b == starting_city and a not in prev_outs and a != original_starting_city:
            #print "b is starting city"
            #print "new returns", returns + [(b,a)]
            #print "new flights", best_flights[:i] + best_flights[(i+1):]
            for rest in generate_trips(n, a, ending_city,
                          best_flights[:i] + best_flights[(i+1):],
                          zips,
                          returns + [(a,b)],
                          prev_outs + [a],
                          original_starting_city):
                yield [(b,a)] + rest
                               
    for i, (a, b) in enumerate(returns):
        if a == starting_city:
            #print "using return trip", a, b
            #print "new returns", returns[:i] + returns[(i+1):]
            for rest in generate_trips(n, b, ending_city,
                                       flights,
                                       zips,
                                       returns[:i] + returns[(i+1):],
                                       prev_outs,
                                       original_starting_city):
                yield [(a,b)] + rest
                
def process_case(case):
    
    n, m, zips, flights = case
    flights = map(clean_flight, flights)
    best_score = None
    cities_to_start_at = sorted(range(n), key=lambda i: int(zips[i]))
    #print "trying in order", cities_to_start_at
    
    for i in cities_to_start_at:
        for trip in generate_trips(n, i, i, flights, zips):
            #print i, trip, "trying"
            score = score_trip(i, zips, trip)
            if score is not None:
                #print i, trip, score
                if best_score is None or score < best_score:
                    best_score = score
        if best_score is not None:
            return best_score
    return best_score

import datetime    

from multiprocessing import Pool
from random import random
import posixfile

def run_me(icase):

    i, case = icase
    #print datetime.datetime.now(), i, case
    result = process_case(case)
    #print result
    #
    print datetime.datetime.now(), i
    return (i,  "Case #" + str(i + 1) + ": " + str(result))
    
if __name__ == "__main__":

    p = Pool(16)
    results = p.map(run_me, enumerate(cases))
    results.sort()
    
    with open(outfile,"w") as g:
        for _, s in results:
            g.write(s + "\n")
            
    
    

