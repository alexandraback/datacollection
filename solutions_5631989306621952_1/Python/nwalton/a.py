def lastword(word):
    if word == "":
        return ""
    lastletter = max(word)
    firstlastindex = word.index(lastletter)
    return lastletter*word.count(lastletter) + lastword(word[:firstlastindex]) + filter(lambda l: l != lastletter, word[firstlastindex:])

i = open("input.txt", "r")
o = open("output.txt", "w")

num_cases = int(i.readline().strip())
for case in range(1, num_cases+1):
    word = i.readline().strip()
    o.write("Case #" + str(case) + ": " + lastword(word) + "\n")
