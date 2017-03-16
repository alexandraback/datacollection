file = open('A-small-attempt0.in', 'r')
out_file = open('output_file.txt', 'w')
amount = file.readline()
for i in range(int(amount)):
    num = int(file.readline())
    if num == 0:
        out_file.write('Case #' + str(i+1) + ': INSOMNIA\n')
        continue
    flags = 0b0000000000
    j = 1
    while True:
        mul = j * num
        j += 1
        for char in str(mul):
            flags |= 2 ** int(char)
        if flags == 0b1111111111:
            out_file.write('Case #' + str(i+1) + ': ' + str(mul) + '\n')
            break
file.close()
out_file.close()
