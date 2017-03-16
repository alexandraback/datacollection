input = file('A-small-attempt0.in','rb+'); output=file('A-small-attempt0.out','wb+')
ncases = int(input.readline().strip())

rcd  = [((0,x),(1,x),(2,x),(3,x)) for x in range(4)]   # columns
rcd += [((y,0),(y,1),(y,2),(y,3)) for y in range(4)]   # rows
rcd += [((0,0),(1,1),(2,2),(3,3))]                     # diagonal
rcd += [((0,3),(1,2),(2,1),(3,0))]                     # antidiagonal

xwins = ['TXXX','XTXX','XXTX','XXXT','XXXX']; owins = ['TOOO','OTOO','OOTO','OOOT','OOOO']

for i in range(ncases):
 board=[[symbol for symbol in input.readline().strip()] for line in range(4)]; k=input.readline()
 potlines=[board[y1][x1]+board[y2][x2]+board[y3][x3]+board[y4][x4] for ((y1,x1),(y2,x2),(y3,x3),(y4,x4)) in rcd]
 if   set(xwins)&set(potlines): output.write('Case #'+str(i+1)+': X won\n')
 elif set(owins)&set(potlines): output.write('Case #'+str(i+1)+': O won\n')
 elif not('.' in ''.join([''.join(line) for line in board])): output.write('Case #'+str(i+1)+': Draw\n')
 else: output.write('Case #'+str(i+1)+': Game has not completed\n')