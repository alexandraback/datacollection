import sys

def input_parser(input_path):
    with open(input_path, 'r') as f:
        c = int(f.readline())
        for case in range(c):
            strs = f.readline().strip()
            yield case, (strs)

def get_output_path(input_path):
    return input_path[:-2] + "out"

def output(f, s):
    print(s)
    f.write(s + "\n")

def remove_number(num_str, letters, rep):
    if rep > 0:
        for i in num_str:
            if letters[ord(i) - 65] >= rep:
                letters[ord(i) - 65] -= rep
            else:
                print('error')
    return letters
        

def problem(s):
    letters = [0]*26
    for i in s:
        letters[ord(i) - 65] += 1
    numbers = [0]*10
    #num_zeros
    numbers[0] = letters[ord('Z') - 65]
    letters = remove_number('ZERO', letters, numbers[0])
    numbers[2] = letters[ord('W') - 65]
    letters = remove_number('TWO', letters, numbers[2])
    numbers[4] = letters[ord('U') - 65]
    letters = remove_number('FOUR', letters, numbers[4])
    numbers[6] = letters[ord('X') - 65]
    letters = remove_number('SIX', letters, numbers[6])
    numbers[8] = letters[ord('G') - 65]
    letters = remove_number('EIGHT', letters, numbers[8])
    numbers[5] = letters[ord('F') - 65]
    letters = remove_number('FIVE', letters, numbers[5])
    numbers[7] = letters[ord('V') - 65]
    letters = remove_number('SEVEN', letters, numbers[7])
    numbers[9] = letters[ord('I') - 65]
    letters = remove_number('NINE', letters, numbers[9])
    numbers[1] = letters[ord('N') - 65]
    letters = remove_number('ONE', letters, numbers[1])
    numbers[3] = letters[ord('T') - 65]

    out = ''
    for i, n in enumerate(numbers):
        if n > 0 :
            out += ''.join([str(i)]*n)
    return out

def main():
    input_path = sys.argv[1]
    with open(get_output_path(input_path), 'w') as g:
        for case, data in input_parser(input_path):
            out = problem(data)
            output(g, "Case #{}: {}".format(case+1, out))

if __name__ == "__main__":
    main()

