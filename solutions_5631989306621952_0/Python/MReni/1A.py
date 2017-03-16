import collections

DEBUG = False
def work(line):
    current_max = -1
    result = ''
    for letter in line:
        if ord(letter) - ord('A') >= current_max:
            result = letter + result
            current_max = ord(letter) - ord('A')
        else:
            result = result + letter
    return result

# A B C D E F G
# H I J K L M N
# O P Q R S T
# U V W X Y Z

count = 1
results = []
with open('A-small-attempt0.in', 'rb') as data:
    data.readline()
    for line in data:
        result = "Case #" + str(count) + ": " + str(work(line.replace('\n', ''))) 
        if DEBUG:
            print result
        results.append(result)
        count = count + 1

if not DEBUG:
    with open('data.out', 'wb') as output_file:
        for result in results:
            output_file.write(result + '\n')
