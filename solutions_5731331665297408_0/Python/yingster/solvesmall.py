#!/usr/bin/env python
import numpy as np
import sys
import pdb
import math

sys.setrecursionlimit(1500000)

solution = set()

class City:
    def __init__(self,zip):
        self.zip = zip
        self.routes = set()
    def add_city(self,mycity):
        self.routes.add(mycity)
        

def solve(cities):
    solution.clear()
    for city in cities:
        newcity = list(cities)
        newcity.remove(city)
        solvesmall(newcity, city.zip, [city])
    return min(list(solution))


def solvesmall(cities,mystring,citypath):
    if len(cities) == 0:
        solution.add(int(mystring))
        return
    else:
        possiblezip = 999999999
        possiblecity = None

        for city in citypath[-1].routes:
            if city in cities:
                if int(city.zip) < possiblezip:
                    possiblezip = int(city.zip)
                    possiblecity = city
        if possiblecity != None:
            newcities = list(cities)
            newcities.remove(possiblecity)
            newpath = list(citypath)
            newpath.append(possiblecity)
            solvesmall(newcities,mystring+possiblecity.zip,newpath)

        if len(citypath) > 1:
            previouscity = citypath[-1]
            newpath = list(citypath)
            newpath.remove(previouscity)
            solvesmall(list(cities), mystring, newpath)



numcase = int(sys.stdin.readline())
for casenum in range(1,numcase+1):
    line = sys.stdin.readline().split()
    N = int(line[0])
    M = int(line[1])
    cities = []
    for _ in range(N):
        cities.append(City(sys.stdin.readline().strip()))
    for _ in range(M):
        line = sys.stdin.readline().split()
        citya = int(line[0])-1
        cityb = int(line[1])-1
        cities[citya].add_city(cities[cityb])
        cities[cityb].add_city(cities[citya])


    print 'Case #' + repr(casenum)+': '+ str(solve(cities))
    
