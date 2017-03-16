#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys

def lottery(path_to_conf):

    with open(path_to_conf) as f:
        content = f.readlines()
    t = int(content[0].replace("\n", ""))

    for i in range(0, t):
        tmp = content[1+i].split(" ")
        a = int(tmp[0])
        b = int(tmp[1])
        k = int(tmp[2].replace("\n", ""))

        count = 0
        for j in range(0, a):
            for l in range(0, b):
                if j&l < k:
                    count += 1
        print("Case #" + str(i+1) + ":", count)
        
        
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_config>")
    else:
        lottery(sys.argv[1])

