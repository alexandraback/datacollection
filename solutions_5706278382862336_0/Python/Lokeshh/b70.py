myDict = {}

def isPossible(a, b, limit):
    if a == 0:
        return True
    try:
        return myDict[(a, b)]
    except KeyError:
        power = 1
        while power <= limit:
            b /= 2.0
            if b != int(b):
                myDict[(a, b)] = False
                return False
            if a/float(b) >= 1:
                myDict[(a, b)] = isPossible(a-b, b, limit - power)
                return myDict[(a, b)]
            power += 1

def doit(a, b):
    power = 1
    while power <= 40:
        b /= 2.0
        if b != int(b):
            return -1
        if a/float(b) >= 1:
            if isPossible(a-b, b, 40-power):
                return power
        power += 1

res = []
for i in range(input()):
    a, b = raw_input().split('/')
    res.append(doit(int(a), int(b)))

for i in range(len(res)):
    if res[i] == -1:
        print 'Case #' + str(i+1) + ': ' + 'impossible'
    else:
        print 'Case #' + str(i+1) + ': ' + str(res[i])

        
