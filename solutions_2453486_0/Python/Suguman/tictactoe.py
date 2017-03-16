infile = open('/home/suguman/Desktop/A-small-attempt3.in', 'r')
outfile = open('/home/suguman/Desktop/output1.txt', 'w')

num = int(infile.readline())
index = 0
while index < num :
    l1 = [infile.readline().strip() for i in range(4)]
    infile.readline()
    l2 = [''.join([l1[j][i] for j in range(4)]) for i in range(4)]
    l3 = [''.join([l1[i][i] for i in range(4)])]
    l4 = [''.join([l1[i][3-i] for i in range(4)])]
    lines = l1 + l2 + l3 +  l4
    print(lines)
    ans = False
    dots = 0
    for row in lines:
        rowans = False
        first = row[0]
        if (first== 'X') or (first == 'O'):
            winner = first
            for i in [1,2,3]:
                if (row[i]== first) or (row[i]=='T'):
                    rowans = True
                else:
                    rowans = False
                    if row[i] == '.':
                        dots = 1
                    break
        elif (first == 'T'):
            second = row[1]
            if (second == 'X') or (second == 'O'):
                winner = second
                for i in [2,3]:
                    if (row[i] == second):
                        rowans = True
                    else:
                        rowans = False
                        if row[i] == '.':
                            dots = 1
                        break
        elif first == '.':
            rowans = False
            dots = 1
        
        if rowans == True:
            ans = True
            break
                
    if ans:
        outfile.write('Case #' + str(index + 1)+': ' + str(winner) + ' won\n')
    else:
        if dots == 0:
            outfile.write('Case #' + str(index + 1)+': ' + 'Draw\n')
        else:
            outfile.write('Case #' + str(index + 1)+': Game has not completed\n')
        
        
    index += 1
