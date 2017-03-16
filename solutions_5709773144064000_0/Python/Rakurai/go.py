import sys

def write(st):
    sys.stdout.write(st)
def writecase(i):
    if i == 0:
        print 'i is 0!!!!!!!!!!!!!!!!!'
    write("Case #%d: " % i)

f = open(sys.argv[1])
T = int(f.readline())

for t in range(1, T+1):
    line = f.readline()
    parts = line.split()
    C = float(parts[0])
    F = float(parts[1])
    X = float(parts[2])

    farms = 0
    best = float('inf')
    seconds = 0.
    
    while True:
        rate = 2 + F * farms

        win_sec = seconds + (X / rate)
        if win_sec > best:
            break

        best = win_sec
        seconds += (C / rate)
        farms += 1

    writecase(t)
    print '%.7f' % best
        
f.close()