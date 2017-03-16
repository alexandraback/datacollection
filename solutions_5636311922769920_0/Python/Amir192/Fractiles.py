__author__ = 'Amir'


f_in = open("C:\Users\Amir\PycharmProjects\GoogleCodeJam\\files\\Pancakes\input2.txt")
f_out = open("C:\Users\Amir\PycharmProjects\GoogleCodeJam\\files\\Pancakes\output2.txt", 'w')


line1 = map(int, (f_in.readline().split(" ")))
numOfCases = line1[0]
caseNum = 0


for n in range (numOfCases):
    caseNum += 1
    line = map(int, (f_in.readline().split(" ")))
    K = line[0]
    C = line[1]
    S = line[2]

    tiles = [k+1 for k in range(K)]

    print 'Case #'  + str(caseNum) + ': '  + ' '.join(map(str, tiles))
    f_out.writelines('Case #'  + str(caseNum) + ': '  + str(tiles) + '\n')