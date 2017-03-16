d = {
        "a": "y",
        "b": "h",
        "c": "e",
        "d": "s",
        "e": "o",
        "f": "c",
        "g": "v",
        "h": "x",
        "i": "d",
        "j": "u",
        "k": "i",
        "l": "g",
        "m": "l",
        "n": "b",
        "o": "k",
        "p": "r",
        "q": "z",
        "r": "t",
        "s": "n",
        "t": "w",
        "u": "j",
        "v": "p",
        "w": "f",
        "x": "m",
        "y": "a",
        "z": "q"
    }


def replace(s):
    s1 = ""
    for i in s:
        if i == " ":
            s1 += " "
        else:
            s1 += d[i]

    return s1


c = input()
for i in range(c):
    s = replace(raw_input())
    print "Case #" + str(i + 1) + ": " + s
