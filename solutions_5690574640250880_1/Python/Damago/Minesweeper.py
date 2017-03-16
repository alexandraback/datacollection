T = int(raw_input())

for i in xrange(T):
  # Input data 
  R,C,M = raw_input().split()
  R = int(R)
  C = int(C) 
  M = int(M)  

  # Explicacion
  #
  # Voy rellenando fila a fila, sin dejar ninguna celda aislada, por eso no pongo
  # ninguna '*' en las dos ultimas columnas. Proceso:
  # De la primera a la anteantepenultima (0-'C-3' inclusives):
  # - si quedan mas '*' que columnas hay, lleno la fila entera
  # - si no, lleno como mucho hasta la antepenultima columna ('C-2' incluida). Vamos,
  #   que las ultimas 2 columnas se dejan libre
  # Para la antepenultima fila (C-2):
  # - a parte de no poner '*' en las dos ultimas columnas, vigilo que para las 2 ultimas
  # filas queden un numero par de '*'
  # Para las 2 ultimas filas:
  # - pongo '*' de dos en dos (una en cada fila), como mucho hasta la antepenultima
  #   columna ('C-2' incluida).
  #
  # Si al final de este proceso, todavia quedan '*' por colocar, es que no es posible.

  # Compute
  # Simple cases: Todas las celdas son '*' menos 1, que es 'c'
  if (M+1) == (R*C):
    grid = [['*' for j in xrange(C)] for k in xrange(R)]
    grid[R-1][C-1] = 'c'  
    R = 0
    M = 0
  else:
    grid = [['.' for j in xrange(C)] for k in xrange(R)]
    grid[R-1][C-1] = 'c'  

  # Simple cases: 2x1, 5x1, 1x7, ...
  if R > 0:
    if (R == 1) or (C == 1):
      if (R == 1):
        for j in xrange(M):
          grid[0][j] = '*'
      else:
        for j in xrange(M):
          grid[j][0] = '*'
      R = 0
      M = 0

  # Simple cases: 2x1, 2x7, 4x2, 8x2, ...
  if R > 0:
    if (R == 2) or (C == 2):
      if ((M+4) <= (R*C)) and ((M%2) == 0):
        if (R == 2):
          for j in xrange(M/2):
            grid[0][j] = '*'
            grid[1][j] = '*'
        else:
          for j in xrange(M/2):
            grid[j][0] = '*'
            grid[j][1] = '*'
        R = 0
        M = 0
      else:
        R = 0
        M = 100 # Impossible

  # ... A partir de aqui solo se ejecuta si R>=3 y C>=3

  # From first to antepenultimate row (both inclusive-> 0, R-3)
  if R > 3:
    j = 0    
    while (j < (R-3)) and (M > 0):
      # if we can fill a whole row
      if M >= C:
        M -= C
        for k in xrange(C):
          grid[j][k] = '*'
      #otherwise, fill partially the row, leaving free last two columns
      else:
        k = 0
        while (k < (C-2)) and (M > 0):
          M -= 1
          grid[j][k] = '*'
          k += 1
      # next row
      j += 1

  # Antepenultimate row (R-2)
  if R > 2:
    if M > 0:
      if M >= C:
        if (M-C)%2 == 0: # sobram pares, asi que relleno toda la fila
          tmp = C
        else:            # impares, asi que paso otro extra a las siguientes filas (para que sean pares) 
          tmp = C - 3
      elif M > (C-2):    # no se puede dejar una celda sola, se pasa otra extra a las siguientes filas
        tmp = C - 3
      else:
        tmp = M

      if tmp > 0:
        M -= tmp
        for k in xrange(tmp):
          grid[R-3][k] = '*'
      

  # Last 2 rows (C-1, C)
  if R > 1:
    if M > 0:           # si queda alguna '*'
      if (M % 2) == 0:  # si son un numero par
        # One '*' on each row at once
        k = 0
        while (k < min(tmp, C-2)) and (M > 0):
          M -= 2
          grid[R-1][k] = '*'
          grid[R-2][k] = '*'
          k += 1

  # Results
  print 'Case #' + str(i+1) + ':'
  if M > 0:
    print 'Impossible'
  else:
    for item in grid:
      print ''.join(item)
  
