#/usr/bin/python

import sys

def get_number_of_friends(max_shyness, audience):
    count = 0
    audience_standing = 0
    for i in range(max_shyness+1):
        while audience_standing < i:
            count += 1
            audience_standing += 1
        audience_standing += int(audience[i])
            
    return count

def read_data_file(filename):
    f = open(filename)
    num_cases = int(f.readline())
    
    max_shyness = [0]*num_cases
    audience_string = [""]*num_cases
    for i in range(num_cases):
        tmp_string = f.readline()
        tmp_list = tmp_string.split()
        max_shyness[i] = int(tmp_list[0])
        audience_string[i] = tmp_list[1]

    f.close()

    return num_cases, max_shyness, audience_string

def write_output(filename, num_friends):
    f = open(filename,'w')
    for i, count in enumerate(num_friends):
        f.write("Case #"+str(i+1)+": "+str(count)+"\n")

    f.close()
    return

if __name__ == '__main__':
    filename = sys.argv[1]

    num_cases, max_shyness, audience_string = read_data_file(filename)

    num_friends = [0]*num_cases

    for i in range(num_cases):
        num_friends[i] = get_number_of_friends(max_shyness[i], audience_string[i])

    write_output("output.txt", num_friends)

    
