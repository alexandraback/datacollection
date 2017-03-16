#!/usr/bin/python
import sys

inputs = [line.strip() for line in sys.stdin]

T = int(inputs[0])

for t in xrange(T):
  s_c, s_j = inputs[t+1].split()
  C = []
  for num in s_c:
    if num == '?':
      C.append(-1)
    else:
      C.append(int(num))

  J = []
  for num in s_j:
    if num == '?':
      J.append(-1)
    else:
      J.append(int(num))

  i = 0
  mindiff = 10**30
  minC = 10**30
  minJ = 10**30

  while i < len(C):
    if C[i] == -1 and J[i] == -1:
      #try 0,1
      Ca = list(C)
      Ja = list(J)
      Ca[i] = 0
      Ja[i] = 1
      for j in xrange(i,len(C)):
       if Ca[j] == -1:
         Ca[j] = 9

      for j in xrange(i,len(C)):
       if Ja[j] == -1:
         Ja[j] = 0

      c_v = int("".join([str(y) for y in Ca]))
      j_v = int("".join([ str(y) for y in Ja]))
      diff = abs(c_v - j_v)
      if diff < mindiff:
        mindiff = diff
        minC = c_v
        minJ = j_v
      elif diff == mindiff:
        if c_v < minC or (c_v == minC and j_v < minJ):
          minC = c_v
          minJ = j_v

      #try 1,0
      Ca = list(C)
      Ja = list(J)
      Ca[i] = 1
      Ja[i] = 0
      for j in xrange(i,len(C)):
       if Ca[j] == -1:
         Ca[j] = 0

      for j in xrange(i,len(C)):
       if Ja[j] == -1:
         Ja[j] = 9

      c_v = int("".join([str(y) for y in Ca]))
      j_v = int("".join([ str(y) for y in Ja]))
      diff = abs(c_v - j_v)
      if diff < mindiff:
        mindiff = diff
        minC = c_v
        minJ = j_v
      elif diff == mindiff:
        if c_v < minC or (c_v == minC and j_v < minJ):
          minC = c_v
          minJ = j_v

      C[i] = 0
      J[i] = 0
      i+=1
      continue

    while i < len(C) and C[i] != -1 and J[i] != -1:
      if C[i] > J[i]:
        # minimize C
        for j in xrange(i,len(C)):
          if C[j] == -1:
            C[j] = 0

        # maximize S
        for j in xrange(i,len(J)):
          if J[j] == -1:
            J[j] = 9

      elif C[i] < J[i]:
        # minimize S
        for j in xrange(i,len(J)):
          if J[j] == -1:
            J[j] = 0

        # maximize C
        for j in xrange(i,len(C)):
          if C[j] == -1:
            C[j] = 9

      i += 1

    # got to a stage where exactly one of C[i] and J[i] is known
    if i < len(C):
      if C[i] != -1: # C[i] =X
        x = C[i]

        # set J[i] to x-1 if possible
        if C[i] != 0:
          Ja = list(J)
          Ja[i] = x-1
          for j in xrange(i,len(J)):
            if Ja[j] == -1:
              Ja[j] = 9

          Ca = list(C)
          for j in xrange(i,len(Ca)):
            if Ca[j] == -1:
              Ca[j] = 0

          c_v = int("".join([str(y) for y in Ca]))
          j_v = int("".join([ str(y) for y in Ja]))
          diff = abs(c_v - j_v)
          if diff < mindiff:
            mindiff = diff
            minC = c_v
            minJ = j_v
          elif diff == mindiff:
            if c_v < minC or (c_v == minC and j_v < minJ):
              minC = c_v
              minJ = j_v

        # set J[i] to x+1
        if C[i] != 9:
          Ja = list(J)
          Ja[i] = x+1
          for j in xrange(i,len(J)):
            if Ja[j] == -1:
              Ja[j] = 0

          Ca = list(C)
          for j in xrange(i,len(Ca)):
            if Ca[j] == -1:
              Ca[j] = 9

          c_v = int("".join([ str(y) for y in Ca]))
          j_v = int("".join([ str(y) for y in Ja]))
          diff = abs(c_v - j_v)
          if diff < mindiff:
            mindiff = diff
            minC = c_v
            minJ = j_v
          elif diff == mindiff:
            if c_v < minC or (c_v == minC and j_v < minJ):
              minC = c_v
              minJ = j_v

        # set J[i] to x and carry on
        J[i] = x
        i += 1

      elif J[i] != -1: # J[i] = X
        x = J[i]

        # set J[i] to x+1
        if J[i] != 9:
          Ja = list(J)
          for j in xrange(i,len(J)):
            if Ja[j] == -1:
              Ja[j] = 9

          Ca = list(C)
          Ca[i] = x+1
          for j in xrange(i,len(Ca)):
            if Ca[j] == -1:
              Ca[j] = 0

          c_v = int("".join([ str(y) for y in Ca]))
          j_v = int("".join([ str(y) for y in Ja]))
          diff = abs(c_v - j_v)
          if diff < mindiff:
            mindiff = diff
            minC = c_v
            minJ = j_v
          elif diff == mindiff:
            if c_v < minC or (c_v == minC and j_v < minJ):
              minC = c_v
              minJ = j_v

        # set C[i] to x-1 if possible
        if J[i] != 0:
          Ja = list(J)
          for j in xrange(i,len(J)):
            if Ja[j] == -1:
              Ja[j] = 0

          Ca = list(C)
          Ca[i] = x-1
          for j in xrange(i,len(Ca)):
            if Ca[j] == -1:
              Ca[j] = 9

          c_v = int("".join([ str(y) for y in Ca]))
          j_v = int("".join([ str(y) for y in Ja]))
          diff = abs(c_v - j_v)
          if diff < mindiff:
            mindiff = diff
            minC = c_v
            minJ = j_v
          elif diff == mindiff:
            if c_v < minC or (c_v == minC and j_v < minJ):
              minC = c_v
              minJ = j_v


        # set C[i] to x and carry on
        C[i] = x
        i += 1

    ######### end of while loop

  c_v = int("".join([ str(y) for y in C]))
  j_v = int("".join([ str(y) for y in J]))
  diff = abs(c_v - j_v)
  if diff < mindiff:
    mindiff = diff
    minC = c_v
    minJ = j_v
  elif diff == mindiff:
    if c_v < minC or (c_v == minC and j_v < minJ):
      minC = c_v
      minJ = j_v

  s_c = str(minC)
  for i in xrange(len(C) - len(str(minC))):
    s_c = "0" + s_c
  s_j = str(minJ)
  for i in xrange(len(C) - len(str(minJ))):
    s_j = "0" + s_j

  print("Case #{0}: {1} {2}".format(t+1, s_c, s_j))
