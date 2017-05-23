f = open('Google Tic-Tac-Toe-Tomek Large.in','r')
g = open('Google Tic-Tac-Toe-Tomek Large.out','w')
def Google_print(filename,answers):
    for i in range(len(answers)):
        filename.write("Case #%s: %s\n" % (str(i+1),answers[i]))
        print "Case #%s: %s" % (str(i+1),answers[i])
    return

def tictactoe(a):
    Xwins = ['XXXX','XXXT','XXTX','XTXX','TXXX']
    Owins = ['OOOO','OOOT','OOTO','OTOO','TOOO']
    for i in range(4):
        row = a[i]
        column = [a[x][i] for x in range(4)]
        column = ''.join(column)
        for j in Xwins:
            if j in row or j in column:
                return 'X won'
        for j in Owins:
            if j in row or j in column:
                return 'O won'
    d1 = [a[0][0],a[1][1],a[2][2],a[3][3]]
    d1 = ''.join(d1)
    d2 = [a[0][3],a[1][2],a[2][1],a[3][0]]
    d2 = ''.join(d2)
    for j in Xwins:
        if j in d1 or j in d2:
            return 'X won'
    for j in Owins:
        if j in d1 or j in d2:
            return 'O won'
    for i in a:
        if '.' in i:
            return 'Game has not completed'
    return 'Draw'

cases = int(f.readline())
answer = []
for i in range(cases):
    a = []
    for j in range(4):
        line = f.readline().rstrip()
        a.append(line)
    answer.append(tictactoe(a))
    discard = f.readline()
Google_print(g,answer)
g.close()
f.close()



        
        
        
        
