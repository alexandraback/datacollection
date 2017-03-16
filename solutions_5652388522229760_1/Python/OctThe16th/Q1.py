f = open('A-large.in', 'r')
a = int(f.readline())

for i in range(a):
    finalN = int(f.readline())
    if (finalN == 0):
        print("Case #" + str(i+1) +": INSOMNIA")
    else:
        y = finalN
        x = set(str(y))
        while(len(x) < 10):
            y = y + finalN
            for ch in str(y):
                x.add(ch)

        print("Case #" + str(i+1) +": " +str(y))





