import sys
import re

if len(sys.argv) != 3:
    print("Usage: python scriptB.py <input_file> <output_file>")
    exit()

input_file = sys.argv[1]
output_file = sys.argv[2]

def check_for_inner(w, inner_letters):
    for c in w:
        if c in inner_letters:
            return True
    return False

def trains(words, last_letter, inner_letters):
    # If there is only one word left
    if len(words) == 1:
        w = words[0]
        # Check if the word contains inner letters
        new_inner = set(inner_letters.copy())
        if last_letter != w[0]:
            new_inner.add(last_letter)
        if check_for_inner(w, new_inner):
            return 0
        else:
            return 1
    # If there are more words left
    res = 0
    for i, w in enumerate(words):
        # Check if the word contains inner letters
        new_inner = set(inner_letters.copy())
        if last_letter != w[0]:
            new_inner.add(last_letter)
        if check_for_inner(w, new_inner):
            continue
        # Update list of inner letters
        if w[0] != w[-1]:
            new_inner |= set(w[:-1])
        # Recursive call
        res += trains(words[:i] + words[i+1:], w[-1], new_inner)

    return res

def collapse(w):
    return re.sub(r'([a-z])\1+', r'\1', w)

def shrink_words(words):
    result = []
    for w in words:
        result.append(collapse(w))
    return result

results = []
with open(input_file, 'r') as f:
    T = int(f.readline())
    for t in range(T):
        N = int(f.readline())
        words = f.readline().replace('\n', '').split(' ')
        words = shrink_words(words)
        res = trains(words, '', set({}))
        results.append('Case #%d: %s\n' % (t+1, res))

with open(output_file, 'w') as f:
    f.writelines(results)