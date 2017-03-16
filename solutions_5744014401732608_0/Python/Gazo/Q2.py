t = int(input())
for i in range(1, t + 1):
    output = ''
    input_string = input().split(" ")
    line = [0]* int(input_string[0])
    matrix_a = []
    for z in range(0, len(line) + 1):
        next_row = list(line)
        matrix_a.append(next_row)

    for j in range(0, int(input_string[0])):
        for z in range(0, int(input_string[0])):
            if j<z :
                matrix_a[j][z] = 1

    if 2**(int(input_string[0]) -2) < int(input_string[1]):
        #impossible case
        output = "IMPOSSIBLE"
    elif 2**(int(input_string[0]) -2) == int(input_string[1]):
        output = "POSSIBLE"
    else:
        matrix_a[0][-1] = 0
        output = "POSSIBLE"


        binary_number = bin(int(input_string[1]) )
        binary_number = str(binary_number)
        binary_number = binary_number[2:]
        while len(binary_number) < int(input_string[0])-1:
            binary_number = "0" + binary_number

        binary_number = binary_number[::-1]


        #print(binary_number)
        for a in range(0,len(binary_number)):
            if binary_number[a] == "0":
                #print(matrix_a[a])
                matrix_a[a+1][len(binary_number)] = 0
            #if matrix_a[a][int(input_string[0])] == '1':














    print("Case #{}: {}".format(i, output))

    if output == "POSSIBLE":
        for j in range(0, int(input_string[0])):
            output2 = ''
            for z in range(0, int(input_string[0])):
                output2 += str(matrix_a[j][z])
            print(output2)

