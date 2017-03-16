
# coding: utf-8

# In[6]:

from collections import defaultdict
def solve(S):
    letters = ['ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE']
    order = [0, 6, 8, 3, 4, 5, 7, 9, 1, 2]
    use = ['Z', 'X', 'G', 'H', 'R', 'F', 'V', 'I', 'N', 'W']
    counter = defaultdict(int)
    for c in S:
        counter[c] += 1
    times = [0] * 10
    for i in range(len(order)):
        times[order[i]] = takes = counter[use[i]]
        for letter in letters[order[i]]:
            counter[letter] -= takes
    ans = []
    for i in range(10):
        ans.extend([str(i)] * times[i])
    return ''.join(ans)

def main():
    T = input()
    for i in xrange(1, T + 1):
        S = raw_input()
        print 'Case #{0}: {1}'.format(i, solve(S))

if __name__ == '__main__':
    main()


# In[1]:




# In[ ]:



