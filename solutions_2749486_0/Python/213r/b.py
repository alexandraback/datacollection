import sys

def read():
    return sys.stdin.readline()

def format(tup):
    return 'Case #%d: %s'%tup

def do2(x,y):
    way = '' 
    if x > 0:
        way += 'WE'*x
    if x < 0:
        way += 'EW'*(-x)
    if y > 0:
        way += 'SN'*y
    if y < 0:
        way += 'NS'*(-y)

    return way

def do(x,y):
    way = ''
    xt = 0; yt = 0
    while xt != x:
        if xt < x:
            xt += 1
            way += 'WE'
        elif xt > x:
            xt -= 1
            way += 'EW'
    
    while yt != y:
        if yt < y:
            yt += 1
            way += 'SN'
        elif xt > x:
            xt -= 1
            way += 'NS'
    return way

for i in xrange(int(read())):
    x, y = map(int,read().split())
    print format((i+1,do2(x,y)))


