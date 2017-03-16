#!/usr/bin/python
import sys

f=open("test.in", "r")
nb_tests = int(f.readline())


for i in range(nb_tests):
    dist = f.readline()
    dist = list(map(int, dist.split(" ")))
    nb_building = dist[0]
    nb_connections = dist[1]
    max_connections = 2 ** (nb_building-2)

    sys.stdout.write("Case #%d: " % (i+1))

    # More than optimal connections
    if nb_connections > max_connections :
        sys.stdout.write("IMPOSSIBLE\n")
        continue

    sys.stdout.write("POSSIBLE\n")
    # Optimal connections
    if nb_connections == max_connections :
        for x in range(nb_building):
            for y in range(nb_building) :
                if y <= x :
                    sys.stdout.write("0")
                else :
                    sys.stdout.write("1")
            sys.stdout.write("\n")
        continue

    # Normal just use power of 2
    a = [i for i in str(bin(nb_connections))[2:]]
    a.append("0")
    a.reverse()
    while len(a) < nb_building :
        a.append("0")

    for x in range(nb_building):
        for y in range(nb_building) :
            if (x == 0 and (y == nb_building-1)) or y <= x or ((y == nb_building-1) and a[x] == "0") :
                sys.stdout.write("0")
            else :
                sys.stdout.write("1")
        sys.stdout.write("\n")
