caseNum = int(input())

def is_match(value, string):
    #print(value, string)
    b = "%0*d" % (len(string), value)
    for i in range(len(string)):
        if string[i] == "?":
            continue
        if string[i] != b[i]:
            return False
    return True

for caseIdx in range(caseNum):
    min_x = 100000
    min_y = 100000
    min_dist = 10000
    x,y = input().strip().split()
    for i in range(10**len(x)):
        for j in range(10**len(x)):
            if is_match(i,x) and is_match(j,y):
                if abs(i-j) < min_dist:
                    min_dist = abs(i-j)
                    (min_x,min_y) = (i,j)
                elif abs(i-j) == min_dist:
                    if (min_x,min_y) > (i,j):
                        (min_x,min_y) = (i,j)
    print("Case #%d: %0*d %0*d" % ( caseIdx+1, len(x), min_x, len(x), min_y))
