__author__ = 'nik'


def parse_input_file():
    pass


def main():
    output_file = open('output', 'w')
    with open('input') as input_file:
        next(input_file)
        case_num = 0
        row1_number = 100
        row2_number = 100
        for line in input_file:
            case_num += 1
            a = int(line[:line.index('/')])
            b = int(line[line.index('/') + 1:])
            c = gcd(a,b)
            a = a / c
            b = b / c
            if (b != 0 and ((b & (b - 1)) == 0)):
                i = 0
                while a < b:
                    a *= 2
                    i += 1
                output = "Case #%d: %d\n"%(case_num,  i)
                print(output)
                output_file.write(output)
            else:
                output = "Case #%d: impossible\n"%(case_num)
                print(output)
                output_file.write(output)



def gcd(a,b):
    while a != b:
        if a > b:
            a = a - b
        else:
            b = b - a
    return a

if __name__ == '__main__': main()