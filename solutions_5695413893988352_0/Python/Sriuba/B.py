#GJAM
#inn.in
from sys import * 

def all(a, b):
        lis = [ [(list(a), list(b))] ] 
        num = []
        for i in range(len(a)):
                if a[i] == '?':
                        num.append(i)
                if b[i] == '?':
                        num.append(-i - 1) 
        for pos in num:
                lis.append([])
                if pos >= 0:
                        for j in lis[-2]:
                                aa, bb = j
                                for k in range(10):
                                                aaa = aa[:]
                                                bbb = bb[:]
                                                aaa[pos] = str(k)
                                                lis[-1].append((aaa, bbb))
                else:
                        p = - pos - 1
                        for j in lis[-2]:
                                aa, bb = j
                                for k in range(10):
                                                aaa = aa[:]
                                                bbb = bb[:]
                                                bbb[p] = str(k) 
                                                lis[-1].append((aaa, bbb))
        return [(int("".join(t[0])), int("".join(t[1]))) for t in lis[-1]]




def execute():
        input_name = argv[1]
        output_name = "out.txt"
        input_file = open(input_name)
        output_file = open(output_name, 'w')

        main(input_file, output_file)

        input_file.close()
        output_file.close()

def main(input_file, output):
        # main algorithm goes here
        T = int(next(input_file))
        for i in range(T):
                c, j = next(input_file).strip().split()
                trips = []
                for pair in all(c, j):
                        cc, jj = pair
                        trips.append( (abs(cc - jj), cc, jj))
                d, x, y = sorted(trips)[0]
                x = str(x)
                y = str(y)
                x = '0'*(len(c) - len(x)) + x
                y = '0'*(len(c) - len(y)) + y

                output.write("Case #" + str(i + 1) + ": " + x + " " +y + "\n")
                print("Case #" + str(i + 1) + ": " + x + " " +y + "\n")

execute()
