d = {"1":"ONE",
     "9":"NINE"}

def solve(input):
    to_return = []
    while "Z" in input:
        input = input.replace("Z", "", 1)
        input = input.replace("E", "", 1)
        input = input.replace("R", "", 1)
        input = input.replace("O", "", 1)
        to_return.append(0)

    while "X" in input:
        input = input.replace("S", "", 1)
        input = input.replace("I", "", 1)
        input = input.replace("X", "", 1)
        to_return.append(6)

    while "W" in input:
        input = input.replace("T", "", 1)
        input = input.replace("W", "", 1)
        input = input.replace("O", "", 1)
        to_return.append(2)

    while "S" in input:
        input = input.replace("S", "", 1)
        input = input.replace("E", "", 2)
        input = input.replace("V", "", 1)
        input = input.replace("N", "", 1)
        to_return.append(7)

    while "V" in input:
        input = input.replace("F", "", 1)
        input = input.replace("I", "", 1)
        input = input.replace("V", "", 1)
        input = input.replace("E", "", 1)
        to_return.append(5)

    while "F" in input:
        input = input.replace("F", "", 1)
        input = input.replace("O", "", 1)
        input = input.replace("U", "", 1)
        input = input.replace("R", "", 1)
        to_return.append(4)

    while "R" in input:
        input = input.replace("T", "", 1)
        input = input.replace("R", "", 1)
        input = input.replace("H", "", 1)
        input = input.replace("E", "", 2)
        to_return.append(3)

    while "T" in input:
        input = input.replace("E", "", 1)
        input = input.replace("I", "", 1)
        input = input.replace("G", "", 1)
        input = input.replace("H", "", 1)
        input = input.replace("T", "", 1)
        to_return.append(8)

    while "O" in input:
        input = input.replace("O", "", 1)
        input = input.replace("N", "", 1)
        input = input.replace("E", "", 1)
        to_return.append(1)

    while "E" in input:
        input = input.replace("N", "", 2)
        input = input.replace("I", "", 1)
        input = input.replace("E", "", 1)
        to_return.append(9)

    return "".join([str(i) for i in sorted(to_return)])



def main():
    input_file = open('A-small-attempt0.in', 'r')
    output_file = open('A-small.out', 'w')
    number_of_cases = int(input_file.readline().strip())
    for i in range(1,number_of_cases+1):
        v = input_file.readline().strip()
        result = solve(v)
        print result
        output_file.write("Case #"+str(i)+": " + result + "\n")

    input_file.close()



if __name__ == "__main__":
    main()