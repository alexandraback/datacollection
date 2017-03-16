import math

def main():    
    f = open('A-large.in', 'r')
    numberOfProblems = int(f.readline())
    out = open('A-large.out','w')
    for case in range(0,numberOfProblems):
        line = f.readline()
        line = line.replace("\n","")
        R,C,W = line.split(" ")
        R = int(R)
        C = int(C)
        W = int(W)
        
        count = 0
        #first add up every row without a hit
        for x in range(0,R-1):
            count += int(C / W)

        count += math.ceil(C / W)
        count += W - 1
        answer = count
        #write answer to out
        out.write("Case #" + str(case+1) + ": " + str(answer) + "\n")





    f.close()
    out.close()

def rev(n):
    return int(str(n)[::-1])

if __name__ == "__main__":
    main()
