import sys

# INPUT DATA AND NUMBER OF TEST CASES
infile = open(sys.argv[1],'r')
T = infile.readline()
T = T.rstrip()

# ITERATE OVER EACH CASE
for index in range(1,int(T)+1):

    B_M = infile.readline().rstrip().split(' ')

    B = int(B_M[0])
    M = int(B_M[1])

    if M > (2 ** (B-2)):
            # OUTPUT IN THE FORM
        print 'Case #' + str(index) + ': IMPOSSIBLE'
    else:
            # OUTPUT IN THE FORM
        print 'Case #' + str(index) + ': POSSIBLE'

        if M == (2 ** (B-2)):
            top_corner = '1'
            M = M - 1
        else:
            top_corner = '0'


        triangle_start = B
        first_line = top_corner
        for index in range(B-1,1,-1):
            if M % 2 == 1:
                first_line = '1' + first_line
                triangle_start = index
            else:
                first_line = '0' + first_line
            M = M / 2
        print '0' + first_line

        for row_num in range(2, B):
            line = ''
            for i in range(row_num):
                line += '0'
            for i in range(B - (row_num)):
                line += '1'
            print line
        
        line = ''
        for i in range(B):
            line += '0'
        print line
