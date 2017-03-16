import sys
import math
import pdb

input_file = sys.argv[1]
output_file = "%s.out" % input_file.split('.')[0]
print "INPUT FILE: %s" % input_file
print "OUTPUT FILE: %s" % output_file

def read_row(file):
    row = file.readline().split()
    return int(row[0]), int(row[1]), int(row[2])

results = list()
history_times = list() 
with open(input_file) as f:
    row_cout = int(f.readline())
    MINE='*'
    SPACE='.'
    CLICKED='c'

    for case_i in xrange(0,row_cout):
        R, C, M = read_row(f)
        
        reverse = False
        if R>C:
            R, C = C, R
            reverse = True
        
        result = None
        if R*C-M==1:
            result = [[MINE for x in xrange(C)] for x in xrange(R)]
            result[0][0] = CLICKED
        elif R==1:
            if M <= C - 2:
                result = [[(MINE if x<M else SPACE) for x in xrange(C)]]
                result[0][C-1] = CLICKED
        elif R==2:
            if M%2==0 and M<=(C-2)*R:
                result = [[(MINE if x*2<M else SPACE) for x in xrange(C)] for x in xrange(R)]
                result[0][C-1] = CLICKED
        elif M <= (R-2)*(C-2):
            result = [[(MINE if i<R-2 and j<C-2 and i*(C-2)+j<M else SPACE) for j in xrange(C)] for i in xrange(R)]
            result[R-1][C-1] = CLICKED
        elif M <= (R-2)*C and ((R-2)*C-M)%2==0:
            result = [[(MINE if (i<R-2 and j<C-2 and i*(C-2)+j<M) or (i<R-2 and j>=C-2 and (R-2)*(C-2)+(i+1)*2<=M) else SPACE) for j in xrange(C)] for i in xrange(R)]
            result[R-1][C-1] = CLICKED
        elif R*C-M >=4 and (R*C-M)%2==0:
            result = [[(MINE if (i<R-2 and j<C-2 and i*(C-2)+j<M) or (i<R-2 and j>=C-2 and (R-2)*(C-2)+(i+1)*2<=M) or ((R-2)*C+(j+1)*2<=M) else SPACE) for j in xrange(C)] for i in xrange(R)]
            result[R-1][C-1] = CLICKED
        elif R*C-M >=9 and (R*C-M)%2==1:
            result = [[(MINE if i<R-2 and j<C-2 and i*(C-2)+j<M else SPACE) for j in xrange(C)] for i in xrange(R)]
            result[R-3][C-3]=SPACE
            M -= (R-2)*(C-2)-1
            for x in xrange(R-3):
                if (M>=2):
                    result[x][C-2]=MINE
                    result[x][C-1]=MINE
                    M -= 2
            for x in xrange(C-3):
                if (M>=2):
                    result[R-2][x]=MINE
                    result[R-1][x]=MINE
                    M -= 2
            result[R-1][C-1] = CLICKED
            
        if (result is not None and reverse):
            results.append([[result[i][j] for i in xrange(R)] for j in xrange(C)])
        else:
            results.append(result)

with open(output_file, 'w') as f:
    i = 1
    for result in results:
        f.write("Case #%s:\n" % (i,))
        if result is None:
            f.write('Impossible\n');
        else:
            f.write('\n'.join(''.join(item for item in row) for row in result) + "\n")
        i += 1
