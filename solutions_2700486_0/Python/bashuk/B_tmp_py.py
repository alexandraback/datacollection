def fact(n):
    res = 1
    if (n == 0):
        return 1
    for i in range(1, n + 1):
        res *= i
    return res

def C(n, k):
    return fact(n) / fact(k) / fact(n - k)

f = open('b_output.txt', 'w')


res = 1.0
f.write('Case #1: ' + str(res) + '\n')

res = 0.0
f.write('Case #2: ' + str(res) + '\n')

res = 0.0
f.write('Case #3: ' + str(res) + '\n')

res = (C(2, 1) + C(2, 2)) * 1.0 / (C(2, 0) + C(2, 1) + C(2, 2))
f.write('Case #4: ' + str(res) + '\n')

res = 1.0
f.write('Case #5: ' + str(res) + '\n')

res = 0.0
f.write('Case #6: ' + str(res) + '\n')

res = (C(2, 1) + C(2, 2)) * 1.0 / (C(2, 0) + C(2, 1) + C(2, 2))
f.write('Case #7: ' + str(res) + '\n')

res = 0.0
f.write('Case #8: ' + str(res) + '\n')

res = 0.0
f.write('Case #9: ' + str(res) + '\n')

res = 0.0
f.write('Case #10: ' + str(res) + '\n')

res = 1.0
f.write('Case #11: ' + str(res) + '\n')

res = 0.0
f.write('Case #12: ' + str(res) + '\n')

res = (C(1, 1)) * 1.0 / (C(1, 0) + C(1, 1))
f.write('Case #13: ' + str(res) + '\n')

res = 0.0
f.write('Case #14: ' + str(res) + '\n')

res = 0.0
f.write('Case #15: ' + str(res) + '\n')

res = 0.0
f.write('Case #16: ' + str(res) + '\n')

res = 1.0
f.write('Case #17: ' + str(res) + '\n')

res = 0.0
f.write('Case #18: ' + str(res) + '\n')

res = 1.0
f.write('Case #19: ' + str(res) + '\n')

res = 0.0
f.write('Case #20: ' + str(res) + '\n')

res = 1.0
f.write('Case #21: ' + str(res) + '\n')

res = 0.0
f.write('Case #22: ' + str(res) + '\n')

res = 0.0
f.write('Case #23: ' + str(res) + '\n')

res = 1.0
f.write('Case #24: ' + str(res) + '\n')

res = 1.0
f.write('Case #25: ' + str(res) + '\n')

res = 0.0
f.write('Case #26: ' + str(res) + '\n')

res = 1.0
f.write('Case #27: ' + str(res) + '\n')

res = 0.0
f.write('Case #28: ' + str(res) + '\n')

res = (C(2, 2)) * 1.0 / (C(2, 0) + C(2, 1) + C(2, 2))
f.write('Case #29: ' + str(res) + '\n')

res = 0.0
f.write('Case #30: ' + str(res) + '\n')

res = 0.0
f.write('Case #31: ' + str(res) + '\n')

res = 1.0
f.write('Case #32: ' + str(res) + '\n')

res = (C(3, 2)) * 1.0 / (C(3, 1) + C(3, 2))
f.write('Case #33: ' + str(res) + '\n')

res = 1.0
f.write('Case #34: ' + str(res) + '\n')

res = 0.0
f.write('Case #35: ' + str(res) + '\n')

res = 1.0
f.write('Case #36: ' + str(res) + '\n')

res = 1.0
f.write('Case #37: ' + str(res) + '\n')

res = 0.0
f.write('Case #38: ' + str(res) + '\n')

res = 0.0
f.write('Case #39: ' + str(res) + '\n')

res = 0.0
f.write('Case #40: ' + str(res) + '\n')

res = 0.0
f.write('Case #41: ' + str(res) + '\n')

res = 0.0
f.write('Case #42: ' + str(res) + '\n')

res = (C(4, 2) + C(4, 3) + C(4, 4)) * 1.0 / (C(4, 0) + C(4, 1) + C(4, 2) + C(4, 3) + C(4, 4))
f.write('Case #43: ' + str(res) + '\n')

res = 1.0
f.write('Case #44: ' + str(res) + '\n')

res = 0.0
f.write('Case #45: ' + str(res) + '\n')

res = (C(3, 3)) * 1.0 / (C(3, 0) + C(3, 1) + C(3, 2) + C(3, 3))
f.write('Case #46: ' + str(res) + '\n')

res = 1.0
f.write('Case #47: ' + str(res) + '\n')

res = 0.0
f.write('Case #48: ' + str(res) + '\n')

res = 1.0
f.write('Case #49: ' + str(res) + '\n')

res = 0.0
f.write('Case #50: ' + str(res) + '\n')

res = (C(1, 1)) * 1.0 / (C(1, 0) + C(1, 1))
f.write('Case #51: ' + str(res) + '\n')

res = (C(2, 1) + C(2, 2)) * 1.0 / (C(2, 0) + C(2, 1) + C(2, 2))
f.write('Case #52: ' + str(res) + '\n')

res = 1.0
f.write('Case #53: ' + str(res) + '\n')

res = (C(6, 3) + C(6, 4)) * 1.0 / (C(6, 2) + C(6, 3) + C(6, 4))
f.write('Case #54: ' + str(res) + '\n')

res = 1.0
f.write('Case #55: ' + str(res) + '\n')

res = 1.0
f.write('Case #56: ' + str(res) + '\n')

res = 1.0
f.write('Case #57: ' + str(res) + '\n')

res = 0.0
f.write('Case #58: ' + str(res) + '\n')

res = 0.0
f.write('Case #59: ' + str(res) + '\n')

res = (C(5, 3) + C(5, 4) + C(5, 5)) * 1.0 / (C(5, 0) + C(5, 1) + C(5, 2) + C(5, 3) + C(5, 4) + C(5, 5))
f.write('Case #60: ' + str(res) + '\n')

res = 0.0
f.write('Case #61: ' + str(res) + '\n')

res = 1.0
f.write('Case #62: ' + str(res) + '\n')

res = 1.0
f.write('Case #63: ' + str(res) + '\n')

res = 1.0
f.write('Case #64: ' + str(res) + '\n')

res = (C(4, 1) + C(4, 2) + C(4, 3) + C(4, 4)) * 1.0 / (C(4, 0) + C(4, 1) + C(4, 2) + C(4, 3) + C(4, 4))
f.write('Case #65: ' + str(res) + '\n')

res = 1.0
f.write('Case #66: ' + str(res) + '\n')

res = (C(1, 1)) * 1.0 / (C(1, 0) + C(1, 1))
f.write('Case #67: ' + str(res) + '\n')

res = 0.0
f.write('Case #68: ' + str(res) + '\n')

res = 0.0
f.write('Case #69: ' + str(res) + '\n')

res = 1.0
f.write('Case #70: ' + str(res) + '\n')

res = 0.0
f.write('Case #71: ' + str(res) + '\n')

res = 1.0
f.write('Case #72: ' + str(res) + '\n')

res = (C(7, 4)) * 1.0 / (C(7, 3) + C(7, 4))
f.write('Case #73: ' + str(res) + '\n')

res = 1.0
f.write('Case #74: ' + str(res) + '\n')

res = 1.0
f.write('Case #75: ' + str(res) + '\n')

res = 1.0
f.write('Case #76: ' + str(res) + '\n')

res = 0.0
f.write('Case #77: ' + str(res) + '\n')

res = (C(4, 3) + C(4, 4)) * 1.0 / (C(4, 0) + C(4, 1) + C(4, 2) + C(4, 3) + C(4, 4))
f.write('Case #78: ' + str(res) + '\n')

res = 0.0
f.write('Case #79: ' + str(res) + '\n')

res = 1.0
f.write('Case #80: ' + str(res) + '\n')

res = 0.0
f.write('Case #81: ' + str(res) + '\n')

res = 1.0
f.write('Case #82: ' + str(res) + '\n')

res = 1.0
f.write('Case #83: ' + str(res) + '\n')

res = 0.0
f.write('Case #84: ' + str(res) + '\n')

res = (C(5, 4) + C(5, 5)) * 1.0 / (C(5, 0) + C(5, 1) + C(5, 2) + C(5, 3) + C(5, 4) + C(5, 5))
f.write('Case #85: ' + str(res) + '\n')

res = (C(1, 1)) * 1.0 / (C(1, 0) + C(1, 1))
f.write('Case #86: ' + str(res) + '\n')

res = (C(3, 1) + C(3, 2) + C(3, 3)) * 1.0 / (C(3, 0) + C(3, 1) + C(3, 2) + C(3, 3))
f.write('Case #87: ' + str(res) + '\n')

res = (C(2, 1) + C(2, 2)) * 1.0 / (C(2, 0) + C(2, 1) + C(2, 2))
f.write('Case #88: ' + str(res) + '\n')

res = (C(5, 2) + C(5, 3) + C(5, 4)) * 1.0 / (C(5, 1) + C(5, 2) + C(5, 3) + C(5, 4))
f.write('Case #89: ' + str(res) + '\n')

res = (C(5, 3) + C(5, 4) + C(5, 5)) * 1.0 / (C(5, 0) + C(5, 1) + C(5, 2) + C(5, 3) + C(5, 4) + C(5, 5))
f.write('Case #90: ' + str(res) + '\n')

res = 0.0
f.write('Case #91: ' + str(res) + '\n')

res = 1.0
f.write('Case #92: ' + str(res) + '\n')

res = (C(3, 2)) * 1.0 / (C(3, 1) + C(3, 2))
f.write('Case #93: ' + str(res) + '\n')

res = 1.0
f.write('Case #94: ' + str(res) + '\n')

res = (C(1, 1)) * 1.0 / (C(1, 0) + C(1, 1))
f.write('Case #95: ' + str(res) + '\n')

res = 0.0
f.write('Case #96: ' + str(res) + '\n')

res = 0.0
f.write('Case #97: ' + str(res) + '\n')

res = 0.0
f.write('Case #98: ' + str(res) + '\n')

res = 1.0
f.write('Case #99: ' + str(res) + '\n')

res = 0.0
f.write('Case #100: ' + str(res) + '\n')

