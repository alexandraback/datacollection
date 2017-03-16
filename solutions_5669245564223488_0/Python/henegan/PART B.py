import re
import math

f1=open('C:/Python27/gaben', 'w+')

rf = open('C:\Users\User\Downloads\B-small-attempt2.in')



testnum = int(rf.readline())

a = 2.0**40

for i in xrange(testnum):
    sets = int(rf.readline())
    ints = ""
    cars = []
    intest = 0
    readins = rf.readline().split()
    for x in xrange(sets):
        car = readins[x]
        start = car[0]
        end = car[-1]
        interior = car[1:-1]
        if len(interior) > 0:
            while interior[0] == start:
                interior = interior[1:]
                if interior == "":
                    break
        if len(interior) > 0:
            while interior[-1] == end:
                interior = interior[:-1]
                if interior == "":
                    break
        cars.append([start,end])
        ints = interior + ","
    for j in 'abcdefghijklmnopqrstuvwxyz':
        if re.findall(j+"[^"+j+"]+"+j,ints):
            f1.write("Case #"+str(i+1)+": 0\n")
            intest = 1
            break
    if intest == 1:
        continue
    depcount = 0
    mult = 1
    cartest = []
    for car in cars:
        cartest.append("".join(car))
    uniques = list(set(cartest))
    duplicates = list(cartest)
    for k in uniques:
        duplicates.remove(k)
    for k in uniques:
        count = 1
        for dup in duplicates:
            if dup == k:
                count += 1
        mult *= math.factorial(count)
    carstring = "".join(cars[0])
    cars.remove(cars[0])
   
    while cars != []:
        breaktest = False
        for car in cars:
            if car[1] == carstring[0]:
                carstring = "".join(car)+carstring
                breaktest = True
                cars.remove(car)
                depcount += 1
                break
        if breaktest:
            continue
        for car in cars:
            if car[0] == carstring[-1]:
                carstring = carstring + "".join(car)
                breaktest = True
                cars.remove(car)
                depcount += 1
                break
        if breaktest:
            continue
        carstring = carstring + "".join(cars[0])
        cars.remove(cars[0])
    finalstring = carstring+ints
    
    for j in 'abcdefghijklmnopqrstuvwxyz':
        if re.findall(j+"[^"+j+"]+"+j,finalstring) != []:
            f1.write("Case #"+str(i+1)+": 0\n")
            intest = 1
            break
    if intest ==1:
        continue
    else:
        result = math.factorial(sets - depcount)
        final = mult*result%1000000007
        f1.write("Case #"+str(i+1)+": "+str(final)+"\n")
        
    


            






##f1.write("Case #"+str(i+1)+": "+str(gen)+"\n")



f1.close()
rf.close()
