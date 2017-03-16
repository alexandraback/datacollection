def getDirection (x, y):
    output_list = list()
    if (x > 0):
        for i in range(x):
            output_list.append('WE')
    else:
        for i in range(-x):
            output_list.append('EW')

    if (y > 0):
        for i in range(y):
            output_list.append('SN')
    else:
        for i in range(-y):
            output_list.append('NS')

    return ''.join(output_list)

if __name__ == "__main__":
    tcases = int(raw_input())
    for itc in range(tcases):
        x, y = map(int, raw_input().split())
        print 'Case #' + str(itc+1) + ': ' + getDirection(x,y)

        
