def multiply(a, b):
    if a == b:
        return '-'
    if a == 'i' and b == 'j':
        return 'k'
    if a == 'i' and b == 'k':
        return '-j'
    if a == 'j' and b == 'i':
        return '-k'
    if a == 'j' and b == 'k':
        return 'i'
    if a == 'k' and b == 'i':
        return 'j'
    if a == 'k' and b == 'j':
        return '-i'

def multiply_string(string):
    sign = 0
    while len(string) > 1:
        string = multiply(string[0],string[1]) + string[2:]
        if string[0] == '-':
            string = string[1:]
            sign += 1
    if sign%2 == 1:
        string = '-' + string
    return string

def find_ijk(string):
    if multiply_string(string) != '-':
        return 'NO' 
    position = 0
    while multiply_string(string[:position]) != 'i':
        position += 1
        if position >= len(string):
            return 'NO'
    while multiply_string(string[:position]) != 'k':
        position += 1
        if position >= len(string):
            return 'NO'
    return 'YES'

file_read = open("Dijkstra-small.txt")
content = file_read.read()
file_read.close()
file_write = open("output.txt",'w')
lines = content.split("\n")

case = 1
while case <= int(lines[0]):
    multiple = int(lines[case*2 -1].split()[1])
    string = lines[case*2]*multiple
    file_write.write("Case #" +`case`+ ": ")
    file_write.write(find_ijk(string))
    file_write.write("\n")
    case += 1
file_write.close()
