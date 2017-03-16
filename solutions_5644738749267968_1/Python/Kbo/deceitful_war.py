#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
import math


def simulate_war(n, naomi, ken):

    count = 0
    naomi = sorted(naomi)
    ken = sorted(ken)
    
    for i in range(0, n):
        choosen_naomi = naomi[-1]
        naomi = naomi[:len(naomi) - 1]
        if ken[-1] < choosen_naomi:
            choosen_ken = ken[0]
            ken = ken[1:]
            count = count + 1
        else:
            for j in reversed(range(0, len(ken))):
                if ken[j] < choosen_naomi:
                    choosen_ken = ken[j+1]
                    if len(ken) > j+2:
                        ken = ken[:j+1] + ken[j+2:]
                    else:
                        ken = ken[:len(ken) - 1]
                    break
    return count


def simulate_deceitful_war(n, naomi, ken):

    count = 0
    naomi = sorted(naomi)
    ken = sorted(ken)

    for i in range(0, n):
        told_naomi = 0
        choosen_naomi = 0
        if naomi[0] < ken[0]:
            choosen_naomi = naomi[0]
            told_naomi = ken[-1] - 0.00001
            naomi = naomi[1:]
        elif naomi[-1] < ken[-1]:
            choosen_naomi = naomi[0]
            told_naomi = ken[-1] - 0.00001
            naomi = naomi[1:]
        elif naomi[-1] > ken[-1]:
            told_naomi = naomi[-1]
            for j in range(0, len(naomi)):
                if naomi[j] > ken[0]:
                    choosen_naomi = naomi[j]
                    if len(naomi) > j+1:
                        naomi = naomi[:j] + naomi[j+1:]
                    else:
                        naomi = naomi[:j]
                    break
        else:
            told_naomi = naomi[-1] 
            choosen_naomi = naomi[-1]
            naomi = naomi[:len(naomi) - 1]
        
        if ken[-1] < told_naomi:
            choosen_ken = ken[0]
            ken = ken[1:]
            count = count + 1
            #print(ken, naomi, choosen_ken, choosen_naomi, told_naomi)
        else:
            for j in reversed(range(0, len(ken))):
                if ken[j] < told_naomi:
                    choosen_ken = ken[j+1]
                    if len(ken) > j+2:
                        ken = ken[:j+1] + ken[j+2:]
                    else:
                        ken = ken[:len(ken) - 1]
                    break
                    #print(choosen_ken, choosen_naomi, told_naomi)
    return count
    

def deceitful_war(path_to_conf):

    with open(path_to_conf) as f:
        content = f.readlines()
    t = int(content[0].replace("\n", ""))

    for i in range(0, t):
        n = int(content[1 + i*3].replace("\n", ""))
        naomi = [float(v) for v in content[2 + i*3].replace("\n", "").split(" ")]
        ken = [float(v) for v in content[3 + i*3].replace("\n", "").split(" ")]
        a = simulate_deceitful_war(n, naomi, ken)
        b = simulate_war(n, naomi, ken)
        print("Case #" + str(i+1) + ": " + str(a) + " " + str(b))
        
        
        
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_config>")
    else:
        deceitful_war(sys.argv[1])

