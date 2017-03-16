import sys
from operator import itemgetter

# INPUT DATA AND NUMBER OF TEST CASES
infile = open(sys.argv[1],'r')
T = infile.readline()
T = T.rstrip()

# ITERATE OVER EACH CASE
for index in range(1,int(T)+1):
    N = int(infile.readline().rstrip());
    lists = []

    # READ IN EACH LIST
    for i in range(2*N-1):
        new_list = infile.readline().rstrip().split(' ')
        for j in range(N):
            new_list[j] = int(new_list[j])
        lists.append(new_list)

    # FIND WHERE THE MISSING LIST BELONGS, AND GRAB ITS PARTNER
    temp = lists[:]
    depth = -1
    for i in range(N):
        if depth < 0:
            temp.sort(key=itemgetter(i))
            if len(temp) > 1 and temp[0][i] == temp[1][i]:
                temp = temp[2:]
            else:
                depth = i
                transpose = temp[0]    

    # FIND EACH ELEMENT BY CHECKING WHERE THE PARTNER FITS
    missing = []
    for i in range(N):
        if i != depth:
            lists.sort(key=itemgetter(i))
            if transpose[i] == lists[0][depth]:
                missing.append(lists[1][depth])
            else:
                missing.append(lists[0][depth])
            lists = lists[2:]
        else:
            lists.sort(key=itemgetter(i))
            missing.append(lists[0][depth])
            lists = lists[1:]
            
        missing[i] = str(missing[i])
    # OUTPUT IN THE FORM
    print 'Case #' + str(index) + ': ' + ' '.join(missing)
