import fileinput

with open('output.txt', 'w') as f:
    T = None
    counter = 0
    for line in fileinput.input():
        if T is None:
            T = int(line.rstrip('\n'))
        else:
            counter += 1
            line = line.rstrip('\n')
            X, R, C = map(int, line.split(' '))
            if X >= 7:
                f.write('Case #%d: RICHARD\n' % counter)
            elif max(R,C) < X:
                f.write('Case #%d: RICHARD\n' % counter)
            elif (X+1)/2 > min(R, C):
                f.write('Case #%d: RICHARD\n' % counter)
            elif (X+1)/2 == min(R, C) and X > 3:
                f.write('Case #%d: RICHARD\n' % counter)
            elif (R*C)%X != 0:
                f.write('Case #%d: RICHARD\n' % counter)
            else:
                f.write('Case #%d: GABRIEL\n' % counter)
