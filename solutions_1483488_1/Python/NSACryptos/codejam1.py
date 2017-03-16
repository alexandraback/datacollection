filename = "C-large.in"
outputN  = "codejam1.txt"


def generate(A, B, number):
    result = 0
    number = str(number)
    org = [number]
    
    if (len(number) == 1):
        return 0
    for i in range (0,len(number)-1):
        number = number[len(number)-1] + number[:(len(number)-1)]
        
        if (int(number) >= A) and (int(number)<=B) and (not (number in org)):
            result = result + 1
            org.append(number)
    return result

def solve(A,B, case):
    output = 0
    for number in range (A,B+1):
        output = output + generate(A,B, number)
    output = output/2
    fi.write("Case #" + str(case) +": " + str(output)+ "\n") 

    
fi = open(outputN, 'r+')
def read(filename):

    f = open(filename)
    line = f.readline()
    line = line.strip()
    T = int(line)
    case = 0
    for l in f:
        case = case + 1
        l = l.strip()
        l = l.split(' ')
        A = int(l[0])
        B = int(l[1])
        solve(A, B, case)
    f.close()
    fi.close()
