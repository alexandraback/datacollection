def path(x,y):
    str1 = ""
    str2 = ""
    if x > 0:
        str1 = x*"WE"
    if x < 0:
        str1 = abs(x)*"EW"
    if y > 0:
        str2 = y*"SN"
    if y < 0:
        str2 = abs(y)*"NS"
    p = str1 + str2
    return p

def runprog(FILE):
    infile = open(FILE,'r')
    outfile = open('a1.out','w')
    line1 = infile.readline()
    T = int(line1.strip('\n'))
    for i in range(T):
        arr = ((infile.readline()).strip('\n')).split(' ')
        x = int(arr[0])
        y = int(arr[1])

        ans = path(x, y)
        outfile.write('Case #' + str(i+1) + ': ' + str(ans) + '\n')

    infile.close()
    outfile.close()
    

