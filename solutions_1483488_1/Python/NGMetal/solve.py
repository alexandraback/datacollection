import sys
from itertools import izip

if __name__ == "__main__":
    fout = open("out", "w")
    fp = open(sys.argv[1])
    for case in range(1, int(fp.readline())+1):
        A, B = map(int, fp.readline().strip().split(" "))
        
        counter = 0
        pairs = []
        for number in range(A, B+1):
            if number > 9:
                string = str(number)
                found = [number]
                for translations in range(len(string)):
                    pair = int(string[translations:] + string[:translations])
                    if pair not in found and pair<B+1 and pair>=A :
                        found.append(pair)
                        counter += 1
        
        fout.write("Case #{}: {}\n".format(case, counter/2))
        
    fp.close()
    fout.close()
