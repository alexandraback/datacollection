#!/usr/bin/env python

import fileinput

__author__ = "Alonso Vidales"
__email__ = "alonso.vidales@tras2.es"
__date__ = "2013-05-12"

class Problem:
    __debug = False

    def resolve(self):
        attacks = 0
        for day in range(self.__endDay + 1):
            if day in self.__tribusByDays:
                for tribu in self.__tribusByDays[day]:
                    succed = False
                    for pos in range(*tribu['range']):
                        if pos not in  self.__wall or self.__wall[pos] < tribu['strength']:
                            succed = True
                            break

                    if succed:
                        attacks += 1

                for tribu in self.__tribusByDays[day]:
                    for pos in range(*tribu['range']):
                        if pos not in  self.__wall or self.__wall[pos] < tribu['strength']:
                            self.__wall[pos] = tribu['strength']

                    if tribu['attacks'] - 1 > 0:
                        tribu['attacks'] -= 1
                        tribu['strength'] += tribu['strengthExange']
                        tribu['range'][0] += tribu['distance']
                        tribu['range'][1] += tribu['distance']
                        if day + tribu['period'] not in self.__tribusByDays:
                            self.__tribusByDays[day + tribu['period']] = [tribu]
                        else:
                            self.__tribusByDays[day + tribu['period']].append(tribu)
  

        return attacks

    def __init__(self, inTribus):
        self.__wall = {}
        self.__tribusByDays = {}
        self.__endDay = 0
        for tribu in inTribus:
            tribuInfo = {
                'd': tribu[0],
                'attacks': tribu[1],
                'range': [tribu[2], tribu[3]],
                'strength': tribu[4],
                'period': tribu[5],
                'distance': tribu[6],
                'strengthExange': tribu[7]
            }

            if tribuInfo['d'] in self.__tribusByDays:
                self.__tribusByDays[tribuInfo['d']].append(tribuInfo)
            else:
                self.__tribusByDays[tribuInfo['d']] = [tribuInfo]

            ends = ((tribuInfo['attacks'] - 1) * tribuInfo['period']) + tribuInfo['d']

            if self.__endDay < ends:
                self.__endDay = ends

        if self.__debug:
            print "EndDay: %s" % (self.__endDay) 
            print "Tribus: %s" % (self.__tribusByDays) 

if __name__ == "__main__":
    problems = int(raw_input())

    for problem in range(problems):
        tribus = int(raw_input())
        tribusInfo = []
        for tribu in range(tribus):
            tribusInfo.append(map(int, raw_input().split()))

        print "Case #%d: %d" % (problem + 1, Problem(tribusInfo).resolve())
