f = open('D-small-attempt0.in','r')

for caseN in range(int(f.readline())):

    X, R, C = map(int, f.readline().split())

    ans = True #answer

    if X > R and X > C:
        ans = False
    elif ((R * C) % X != 0):
        ans = False 
    elif X in (1, 2, 3):
        ans = True
    elif X == 4:
        ans = min(R, C) > 2
    elif X == 5:
        ans = not(min(R, C) == 3 and max(R, C) == 5)
    elif X == 6:
        ans = min(R, C) > 3
    elif X >= 7:
        ans = False
    elif ((X + 1) // 2) > min(R, C):
        ans = False
		
    print('Case #%d:' % (caseN + 1), 'GABRIEL' if ans else 'RICHARD')