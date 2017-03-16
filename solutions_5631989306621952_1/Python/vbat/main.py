from itertools import tee, izip

importResults = list()

while True:
    try:
        text = raw_input()
        if len(text.strip()) == 0:
            break
        else:
            importResults.append(text.strip())
    except EOFError:
        break

def processCase(data):
    if len(data) <= 1:
        return data
    else:
        max_char = max(data)
        first_max_position = data.find(max_char)
        prefix = data[0:data.find(max_char)]
        suffix = data[data.find(max_char):]
        last_word = processCase(prefix)
        for char in suffix:
            if char == max_char:
                last_word = char + last_word
            else:
                last_word = last_word + char
        return last_word


for i in range(len(importResults)):
    if i == 0:
        pass # this corresponds to the number of items
    else:
        print "Case #{case_id}: {result}".format(case_id = i, result = processCase(importResults[i]))



