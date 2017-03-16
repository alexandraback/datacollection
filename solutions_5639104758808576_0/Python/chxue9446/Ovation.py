def string_to_list(string):
    lst = []
    for i in range(len(string)):
        lst.append(int(string[i]))
    return lst

def invite(config):
    if len(config) == 0:
        return 0
    add = len(config) - 1 - sum(config[:-1])
    if add < 0:
        add = 0
    config[0] += add
    return add + invite(config[:-1])

file_read = open("Ovation-small.txt")
content = file_read.read()
file_read.close()
file_write = open("output.txt",'w')
lines = content.split("\n")

case = 1
while case <= int(lines[0]):
    info_string = lines[case].split()[1]
    info_lst = string_to_list(info_string)
    file_write.write("Case #" +`case`+ ": ")
    file_write.write(str(invite(info_lst)))
    file_write.write("\n")
    case += 1
file_write.close()
