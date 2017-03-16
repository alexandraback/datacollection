def rank_and_file(string_array):
    count = dict()
    for string in string_array:
        numbs = map(int, string.split())
        for num in numbs:
            if num not in count:
                count[num] = 1
            else:
                count[num] += 1
    output = []
    for key in count:
        if count[key]%2 == 1:
            output += [key]
    output.sort()
    output_string = str(output[0])
    for num in output[1:]:
        output_string += ' ' + str(num)
    return output_string

with open('B-large.in', 'r') as ipf, open('rankAndFile.txt', 'w') as opf:
    source = ipf.read()
    line = source.splitlines()
    index = 1
    for i in range(int(line[0])):
        length = int(line[index])
        opf.write('Case #' + str(i+1) + ': ')
        opf.write(rank_and_file(line[index+1:index+2*length]) + '\n')
        index = index+2*length
