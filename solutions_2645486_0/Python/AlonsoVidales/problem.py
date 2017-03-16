#!/usr/bin/env python

import fileinput

__author__ = "Alonso Vidales"
__email__ = "alonso.vidales@tras2.es"
__date__ = "2013-04-12"

class Problem:
    __debug = False

    def __checkByDeep(self, energy, activities, gained): #, inAux = []):
        if self.__debug:
            print "--- Checking ---"
            print "Energy: %s Gained: %s Activities: %s Road: " % (energy, gained, activities)#, inAux)

        if energy <= 0 or len(activities) == 0:
            if gained > self.__maxGain:
                self.__maxGain = gained
            return

        if self.__regain > energy:
            newEnergy = self.__regain
            if newEnergy > self.__initEnergy:
                newEnergy = self.__initEnergy
            self.__checkByDeep(newEnergy, activities[1:], gained + (energy * activities[0])) #, aux)

        for energyToSpend in xrange(0, energy + 1):
            newEnergy = energy - energyToSpend + self.__regain
            if newEnergy > self.__initEnergy:
                newEnergy = self.__initEnergy
            #aux = inAux[:]
            #aux.append(energyToSpend)
            self.__checkByDeep(newEnergy, activities[1:], gained + (energyToSpend * activities[0])) #, aux)

        return

    def resolve(self):
        self.__checkByDeep(self.__energy, self.__activities, 0)

        return self.__maxGain

    def __init__(self, inEnergy, inRegain, inActivities):
        self.__maxGain = 0
        self.__initEnergy = inEnergy
        self.__energy = inEnergy
        self.__regain = inRegain
        self.__activities = inActivities
        if self.__debug:
            print "Energy: %s" % (self.__energy) 
            print "Regain: %s" % (self.__regain) 
            print "Activities: %s" % (self.__activities) 

if __name__ == "__main__":
    lines = [line.replace('\n', '') for line in fileinput.input()]

    for problem in xrange(0, int(lines[0])):
        info = map(int, lines[(problem * 2) + 1].split())
        print "Case #%d: %s" % (
            problem + 1,
            Problem(
                info[0],
                info[1],
                map(int, lines[(problem * 2) + 2].split())).resolve())
