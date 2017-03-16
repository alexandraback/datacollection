import copy

f = open("B-large.in", 'r')
g = open("B-large.out", 'w')
cases = int(f.readline())

def fact(n):
    m = 1
    for i in range(1, n+1):
        m = m * i
    return m


casenr = 0
for case in range(0, cases):
    casenr += 1
    g.write('Case #' + str(casenr) + ": ")

    ncars = int(f.readline())
    cars = f.readline().split()

    print('Case #' + str(casenr) + ": ")
    print ncars, cars
    starting= []
    ending = []
    singles = []

    shortenedcars = []

    for car in cars:
        s = car[0]
        for char in car[1:]:
            if char != s[-1]:
                s += char
        shortenedcars.append(s)

    cars = shortenedcars
    print cars    
    for car in cars:
        starting.append(car[0])
        ending.append( car[-1])
        if car[0] == car[-1]:
            singles.append(car[0])
        else:
            singles.append('*')

    print starting
    print ending
    print singles
    sets = []

    while len(cars):
        newset = [cars.pop(0)]
        starting.pop(0)
        ending.pop(0)
        singles.pop(0)
        
        begins = newset[0][0]
        ends = newset[-1][-1]


        while begins in ending or ends in starting or ends in singles or begins in singles:
            if ends in singles:
                index = singles.index(ends)
                newset.append(cars.pop(index))
                starting.pop(index)
                ending.pop(index)
                singles.pop(index)
                begins = newset[0][0]
                ends = newset[-1][-1]
            elif begins in singles:
                index = singles.index(begins)
                newset.insert(0, cars.pop(index))
                starting.pop(index)
                ending.pop(index)
                singles.pop(index)
                begins = newset[0][0]
                ends = newset[-1][-1]
            elif ends in starting:
                index = starting.index(ends)
                newset.append(cars.pop(index))
                starting.pop(index)
                ending.pop(index)
                singles.pop(index)
                begins = newset[0][0]
                ends = newset[-1][-1]
            elif begins in ending:
                index = ending.index(begins)
                newset.insert(0, cars.pop(index))
                starting.pop(index)
                ending.pop(index)
                singles.pop(index)
                begins = newset[0][0]
                ends = newset[-1][-1]

        sets.append(newset)
    print sets    

    setmultipliers = []
    for s in sets:
        setmultiplier = 1
        streak = 1
        for i in range(0, len(s)-1):
            if s[i][0] == s[i+1][-1]:
                print "incrementing streak"
                streak += 1
            else:
                setmultiplier = setmultiplier * fact(streak)
                streak = 1
        setmultiplier = setmultiplier * fact(streak)
        
        setmultipliers.append(setmultiplier)
    print setmultipliers

    combs = 1
    for multiplier in setmultipliers:
        combs *= multiplier

    combs *= fact(len(sets))

    print combs

    usedchars = []
    longstring = ''
    for s in sets:
        for el in s:
            longstring += el
    print longstring

    usedchars = ''
    for char in longstring:
        if char in usedchars and char != usedchars[-1]:
            combs = 0
            break
        else:
            if not char in usedchars:
                usedchars += char
            
    print combs
    g.write(str(combs % 1000000007) + '\n')
    
g.close()
