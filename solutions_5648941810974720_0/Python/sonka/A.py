#!/usr/bin/python
import sys

inputs = [line.strip() for line in sys.stdin]

T = int(inputs[0])

for t in xrange(T):
  s = inputs[t+1]
  tb = dict()
  for let in s:
    if let in tb:
      tb[let] += 1
    else:
      tb[let] = 1

  numbers = []
  if 'Z' in tb:
    f = tb['Z']
    for i in xrange(f):
      numbers.append(0)
    tb['Z'] = 0
    tb['E'] -= f
    tb['R'] -= f
    tb['O'] -= f

  if 'W' in tb:
    f = tb['W']
    for i in xrange(f):
      numbers.append(2)
    tb['W'] = 0
    tb['T'] -= f
    tb['O'] -= f

  if 'X' in tb:
    f = tb['X']
    for i in xrange(f):
      numbers.append(6)
    tb['X'] = 0
    tb['S'] -= f
    tb['I'] -= f

  if 'S' in tb and tb['S'] != 0:
    f = tb['S']
    for i in xrange(f):
      numbers.append(7)
    tb['S'] = 0
    tb['E'] -= 2*f
    tb['V'] -= f
    tb['N'] -= f

  if 'G' in tb and tb['G'] != 0:
    f = tb['G']
    for i in xrange(f):
      numbers.append(8)
    tb['G'] = 0
    tb['E'] -= f
    tb['I'] -= f
    tb['H'] -= f
    tb['T'] -= f

  if 'V' in tb and tb['V'] != 0:
    f = tb['V']
    for i in xrange(f):
      numbers.append(5)
    tb['V'] = 0
    tb['F'] -= f
    tb['I'] -= f
    tb['V'] -= f

  if 'I' in tb and tb['I'] != 0:
    f = tb['I']
    for i in xrange(f):
      numbers.append(9)
    tb['I'] = 0
    tb['N'] -= 2*f
    tb['E'] -= f

  if 'N' in tb and tb['N'] != 0:
    f = tb['N']
    for i in xrange(f):
      numbers.append(1)
    tb['N'] = 0
    tb['O'] -= f
    tb['E'] -= f

  if 'H' in tb and tb['H'] != 0:
    f = tb['H']
    for i in xrange(f):
      numbers.append(3)
    tb['H'] = 0
    tb['T'] -= f
    tb['R'] -= f
    tb['E'] -= 2*f

  if 'F' in tb and tb['F'] != 0:
    f = tb['F']
    for i in xrange(f):
      numbers.append(4)

  out = "".join([str(x) for x in sorted(numbers)])
  print("Case #{0}: {1}".format(t+1, out))
