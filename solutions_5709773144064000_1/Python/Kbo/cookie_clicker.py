#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys

def cookie_clicker(path_to_conf):

    with open(path_to_conf) as f:
        content = f.readlines()
    n = int(content[0].replace("\n", ""))

    for i in range(0, n):
        tmp = content[1 + i].split(" ")
        c = float(tmp[0])
        f = float(tmp[1])
        x = float(tmp[2])

        n = 0.
        r = 2.
        t = 0.
        while n < x:
            if n < c:
              t = t + (c-n)/r
              n = c
            else:
                n = n + r
            if n >= c:
                remaining_1 = (x-n)/r
                remaining_2 = (x-n+c)/(r+f)
                if remaining_2 > remaining_1:
                    t = t + (x-n)/r
                    break
                else:
                    n = n - c
                    r = r + f
        print ("Case #" + str(i+1) + ": " + str(t))
        

        

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_config>")
    else:
        cookie_clicker(sys.argv[1])

