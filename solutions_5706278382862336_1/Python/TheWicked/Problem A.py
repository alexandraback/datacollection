from fractions import gcd

def main(input_address):
    input_file = open(input_address, "r")
    solve(input_file, open("D:\\output.txt","w"))

def solve(input_file, output_file):
    cases_number = int(input_file.readline())
    for k in range(cases_number):
        fract = input_file.readline()
        fract = fract.split("/")
        fract[0] = float(fract[0])
        fract[1] = float(fract[1])
        
        g = gcd(fract[0],fract[1])
        fract[0] = fract[0] / g
        fract[1] = fract[1] / g


        answer = calc(list(fract))
        
        output_file.write("Case #" +
                          str(k+1) + ": " + answer + "\n")
    input_file.close()
    output_file.close()

def calc(x):
    d = parent(x)
    if d <0:
        return "impossible"
    return str(d)


def parent(x):
    for i in range(1,40):
        t=(((2**i)*x[0])/x[1]) - 1
        if len(str(t.as_integer_ratio()[0]))>11 or len(str(t.as_integer_ratio()[1]))>11:
            return -1
        if t>= 0 and t<=1:
            return i
    return -1

main("D:\\input.in")
