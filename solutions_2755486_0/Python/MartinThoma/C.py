#!/usr/bin/env python
# -*- coding: utf-8 -*-

from collections import defaultdict

def prepareTribes(tribes):
    tribeStack = []
    for tribe in tribes:
        for attackNumber in range(0, tribe["ni"]):
            tribeStack.append({
                "day" :tribe["di"]+attackNumber*tribe["delta_di"],
                "west":2*(tribe["wi"]+attackNumber*tribe["delta_pi"]),
                "east":2*(tribe["ei"]+attackNumber*tribe["delta_pi"]),
                "height":tribe["si"]+attackNumber*tribe["delta_si"]
            })
    return sorted(tribeStack, key=lambda tribe: tribe["day"])

def runAttack(wall, tribe):
    increase = []
    for i in xrange(tribe["west"], tribe["east"] + 1):
        if wall[i] < tribe["height"]: # wall-ee :-)
            increase.append({"wallPos" : i, "height" : tribe["height"]})

    return increase

def solve(tribes):
    wall = defaultdict(int)
    tribeStack = prepareTribes(tribes)
    #for tribe in tribeStack:
    #    print tribe["day"], "[" + str(tribe["west"]) + "," + str(tribe["east"])+"]", tribe["height"]
    successes = 0
    increase = []
    for i, tribe in enumerate(tribeStack):
        increaseTmp = runAttack(wall, tribe)
        #print wall
        #print tribe
        if len(increaseTmp) > 0:
            successes += 1

        increase += increaseTmp

        if i+1==len(tribeStack) or tribeStack[i+1]["day"] > tribe["day"]:
            for el in increase:
                if wall[el["wallPos"]] < el["height"]:
                    wall[el["wallPos"]] = el["height"]
    return successes

if __name__ == "__main__":
    testcases = input()
      
    for caseNr in xrange(1, testcases+1):
        N = input() # Number of tribes attacking the wall
        tribes = []
        for tribe in range(N):
            di, ni, wi, ei, si, delta_di, delta_pi, delta_si = raw_input().split(" ")
            tribes.append({"di":int(di), # the day of the tribe's first attack
            "ni": int(ni), # the number of attacks from this tribe
            "wi": int(wi), # the westmost 
            "ei": int(ei), # and eastmost points respectively of the Wall attacked on the first attack
            "si": int(si), # the strength of the first attack
            "delta_di": int(delta_di), # the number of days between subsequent attacks by this tribe
            "delta_pi": int(delta_pi), # the distance this tribe travels to the east between subsequent attacks (if this is negative, the tribe travels to the west)
            "delta_si": int(delta_si) # the change in strength between subsequent attacks
            })
        print("Case #%i: %s" % (caseNr, solve(tribes)))
