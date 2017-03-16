import sys
from itertools import izip

if __name__ == "__main__":
    fout = open("out", "w")
    fp = open(sys.argv[1])
    for case in range(1, int(fp.readline())+1):
        numbers = map(int, fp.readline().strip().split(" "))
        googlers = numbers[0]
        surprises = numbers[1]
        score = numbers[2]
        results = numbers[3:]

        counter = len(filter(lambda x: x>=score*3-2, results))
        counter2 = len(filter(lambda x: (x<score*3-2 and x>=score*3-4 and x!=0), results))
        counter += min(counter2, surprises)

        fout.write("Case #{}: {}\n".format(case, counter))
        
    fp.close()
    fout.close()
