def get_biggest_string(S):
    output = ""
    for char in S:
        if len(output) == 0:
            output += char
        elif char >= output[0]:
            output = char + output
        else:
            output += char
    return output


with open("input.txt") as f:
    with open("output.txt", "w") as outf:
        for i, line in enumerate(f):
            if i == 0:
                continue
            else:
                outstring = get_biggest_string(line)
                outf.write("Case #" + str(i) + ": " + outstring)


