
t = input()

for i in range(t):
    tmp = map(int, raw_input().split())
    myout = 'Case #' + str(i + 1) + ': '
    if tmp[1] > 0:
        myout += 'N'
        myout += 'SN' * (tmp[1] - 1)
        if tmp[0] > 0:
            myout += 'WE' * tmp[0]
        else:
            myout += 'EW' * (-tmp[0])
    elif tmp[1] < 0:
        myout += 'S'
        myout += 'NS' * (-tmp[1] - 1)
        if tmp[0] > 0:
            myout += 'WE' * tmp[0]
        else:
            myout += 'EW' * (-tmp[0])
    else:
        if tmp[0] > 0:
            myout += 'E'
            myout += 'WE' * (tmp[0] - 1)
        else:
            myout += 'W'
            myout += 'EW' * (-tmp[0] - 1)
    print myout

    
